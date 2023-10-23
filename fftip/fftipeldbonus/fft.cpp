#include"fft.h"
#include<stdio.h>

void FFTipfn(FP &FFTIN,FP &FFTOUT){
#pragma HLS INTERFACE axis register both port=FFTOUT
#pragma HLS INTERFACE axis register both port=FFTIN
#pragma HLS INTERFACE ap_ctrl_none port=return
    DTYPE tempout_R[FFTSIZE],tempout_I[FFTSIZE];
    int i_lower;    /* Index of lower point in butterfly */
    int i,j;
    int stage;
    int subDFTSize; //Size of DFT in each stage of FFT
    int BFWidth;      /*Butterfly Width*/
    DTYPE temp_R;   /*temporary storage complex variable*/
    DTYPE temp_I;   /*temporary storage complex variable*/
    DTYPE BFWeight_cos, BFWeight_sin;
    DTYPE FFTIn_R[FFTSIZE],FFTIn_I[FFTSIZE];
    struct com val;
    COMPLEXF siu;
    generateinput: for(i= 0; i < FFTSIZE; ++i) {
    #pragma HLS PIPELINE
    	FFTIN.read(val);
    	siu = val.data;
    	FFTIn_R[i]=siu.real();
    	FFTIn_I[i]=siu.imag();
      }
    /*=====================BEGIN BIT REBERSAL===========================*/

    bitreversal:for (i = 0; i < FFTSIZE; ++i) {
    #pragma HLS PIPELINE
     tempout_R[reverse(i)] = FFTIn_R[i];
     tempout_I[reverse(i)] = FFTIn_I[i];
    }
    /*++++++++++++++++++++++END OF BIT REVERSAL++++++++++++++++++++++++++*/

    /*=======================BEGIN: FFT=========================*/
    // Do FFTSTAGES of butterflies
    for(stage=1; stage<= FFTSTAGES; stage++)
      {
        subDFTSize = 1 << stage;    // DFT = 2^stage = points in sub DFT
        BFWidth = subDFTSize >> 1;
        for(j=0;j<BFWidth;){
			BFWeight_cos = W_real[j * (FFTSIZE>>stage)];
			BFWeight_sin = W_imag[j * (FFTSIZE>>stage)];
			for(i =j ; i < FFTSIZE; i += subDFTSize){
				i_lower = i + BFWidth;      //index of lower point in butterfly
				temp_R = tempout_R[i_lower] * BFWeight_cos - tempout_I[i_lower] * BFWeight_sin;
				temp_I = tempout_I[i_lower] * BFWeight_cos + tempout_R[i_lower] * BFWeight_sin;

				tempout_R[i_lower] = tempout_R[i] - temp_R;
				tempout_I[i_lower] = tempout_I[i] - temp_I;
				tempout_R[i] = tempout_R[i] + temp_R;
				tempout_I[i] = tempout_I[i] + temp_I;
			}
			j++;
            }
      }
    generateoutput: for(i= 0; i < FFTSIZE; ++i) {
#pragma HLS PIPELINE
    	siu.real(tempout_R[i]);
    	siu.imag(tempout_I[i]);
    	val.data=siu;
    	val.keep=-1;
    	val.last=(i==FFTSIZE-1)?1:0;
    	FFTOUT.write(val);
  }

}

