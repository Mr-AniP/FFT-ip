#include<stdio.h>
#include"fft.h"

void FFTipfn_gold(DTYPE FFTIn_R[],DTYPE FFTIn_I[],DTYPE FFTOut_R[],DTYPE FFTOut_I[])
{

  DTYPE temp_R;   /*temporary storage complex variable*/
  DTYPE temp_I;   /*temporary storage complex variable*/
  int i,j;      /* loop indexes */
  int i_lower;    /* Index of lower point in butterfly */

  int stage;
  int subDFTSize; //Size of DFT in each stage of FFT
  int BFWidth;      /*Butterfly Width*/
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
//  for (i = 0; i < FFTSIZE; ++i) {
//	FFT_output[i].real=FFTOut_R[i];
//	FFT_output[i].imag=FFTOut_R[i];
//  }
}
void init_arr(DTYPE FFTIn_R[],DTYPE FFTIn_I[]){
	for(int i=0;i<FFTSIZE;i++){
		FFTIn_R[i]=i;
		FFTIn_I[i]=0;
	}
}
int main(){
	int fail=0;
	FP FFTIN;
	FP FFTOUT;
	COMPLEXF out[FFTSIZE];
	DTYPE FFTIn_R[FFTSIZE],FFTIn_I[FFTSIZE],FFTOut_Rs[FFTSIZE],FFTOut_Is[FFTSIZE];
	init_arr(FFTIn_R,FFTIn_I);
	FFTipfn_gold(FFTIn_R,FFTIn_I,FFTOut_Rs,FFTOut_Is);
	struct com val;
	COMPLEXF siu;
	for(int i=0;i<FFTSIZE;i++){
		siu.real(FFTIn_R[i]);
		siu.imag(FFTIn_I[i]);
		val.data=siu;
		val.last=(i==FFTSIZE-1)?1:0;
		FFTIN.write(val);
	}
	FFTipfn(FFTIN,FFTOUT);
	for(int i=0;i<FFTSIZE;i++){
		struct com valOut;
		FFTOUT.read(valOut);
		int las = valOut.last;
		out[i]= valOut.data;
	}
	for(int i=0;i<FFTSIZE;i++){
		if(out[i].real()!=FFTOut_Rs[i] || out[i].imag()!=FFTOut_Is[i]){fail=1;printf("Failed at i = %d\n",i);}
	}
	if(fail)printf("FAILED\n");
	else printf("PASSED\n");
	return fail;
}
