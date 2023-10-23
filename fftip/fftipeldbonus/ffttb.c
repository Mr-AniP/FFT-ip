#include<stdio.h>
#include"fft.h"

void init_arr(float _Complex inr[]){
	for(int i=0;i<FFTSIZE;i++){
		inr[i]=i;
	}
}
void FFTipfn_gold(float _Complex FFT_input[FFTSIZE], float _Complex FFT_output[FFTSIZE])
{

  DTYPE temp_R;   /*temporary storage complex variable*/
  DTYPE temp_I;   /*temporary storage complex variable*/
  DTYPE FFTIn_R[FFTSIZE];
  DTYPE FFTIn_I[FFTSIZE];
  DTYPE FFTOut_R[FFTSIZE];
  DTYPE FFTOut_I[FFTSIZE];
  int i,j;      /* loop indexes */
  int i_lower;    /* Index of lower point in butterfly */

  int stage;
  int subDFTSize; //Size of DFT in each stage of FFT
  int BFWidth;      /*Butterfly Width*/
  for (i = 0; i < FFTSIZE; ++i) {
      FFTIn_R[i] = crealf(FFT_input[i]);
      FFTIn_I[i] = cimagf(FFT_input[i]);
    }

  /*=====================BEGIN BIT REBERSAL===========================*/
  for (i = 0; i < FFTSIZE; ++i) {
    FFTOut_R[reverse(i)] = FFTIn_R[i];
    FFTOut_I[reverse(i)] = FFTIn_I[i];
  }
  /*++++++++++++++++++++++END OF BIT REVERSAL++++++++++++++++++++++++++*/

  /*=======================BEGIN: FFT=========================*/
  // Do FFTSTAGES of butterflies
  DTYPE BFWeight_cos, BFWeight_sin;
 // For N-point FFT, there are log2(N) stages
  for(stage=1; stage<= FFTSTAGES; stage++)
  {
    subDFTSize = 1 << stage;    // DFT = 2^stage = points in sub DFT
    BFWidth = subDFTSize >> 1;       // Butterfly WIDTHS in sub-DFT (FFTSIZE of sub-DFT/2)
    // Perform butterflies for j-th stage
    // This loop runs for the iteration equal to BF width
    // In 4-point FFT, BF width is 1 in stage 1 and 2 in stage 2
    // In 8-point FFT, BF width is 1 in stage 1, 2 in stage 2 and 4 in stage 3
    butterfly:for(j=0; j<BFWidth; j++)
    {
    	BFWeight_cos = W_real[j * (FFTSIZE>>stage)];
    	BFWeight_sin = W_imag[j * (FFTSIZE>>stage)];

		// This loop is for all butterflies in a stage that use same W**k
		// In 4-point FFT, we have two BFs in stage 1
		// In 8-point FFT, we have four BFs in stage 1 and two BFs in stage 2
		subDFTSize:for(i =j ; i < FFTSIZE; i += subDFTSize)
		  {
			i_lower = i + BFWidth;      //index of lower point in butterfly
			temp_R = FFTOut_R[i_lower] * BFWeight_cos - FFTOut_I[i_lower] * BFWeight_sin;
			temp_I = FFTOut_I[i_lower] * BFWeight_cos + FFTOut_R[i_lower] * BFWeight_sin;

			FFTOut_R[i_lower] = FFTOut_R[i] - temp_R;//- temp_R;
			FFTOut_I[i_lower] = FFTOut_I[i] - temp_I;
			FFTOut_R[i] = FFTOut_R[i] + temp_R;
			FFTOut_I[i] = FFTOut_I[i] + temp_I;
		  }
	}
  }
  for (i = 0; i < FFTSIZE; ++i) {
	FFT_output[i]=FFTOut_R[i]+FFTOut_I[i]*I;
  }
}



int main(){
	int fail=0;
	float complex fftin[FFTSIZE],fftouth[FFTSIZE],fftouts[FFTSIZE];
	init_arr(fftin);
	FFTipfn_gold(fftin,fftouts);
	FFTipfn(fftin,fftouth);
	for(int i=0;i<FFTSIZE;i++){
		if(fftouth[i]!=fftouts[i])fail=1;
	}
	if(fail)printf("FAILED\n");
	else printf("PASSED\n");
	return fail;
}
