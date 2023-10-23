// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Wed May 24 19:46:45 2023
// Host        : SHANNON-PC1 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top design_1_FFTipfn_0_0 -prefix
//               design_1_FFTipfn_0_0_ design_1_FFTipfn_0_1_stub.v
// Design      : design_1_FFTipfn_0_1
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "FFTipfn,Vivado 2019.1" *)
module design_1_FFTipfn_0_0(ap_clk, ap_rst_n, FFTIN_TVALID, FFTIN_TREADY, 
  FFTIN_TDATA, FFTIN_TKEEP, FFTIN_TLAST, FFTOUT_TVALID, FFTOUT_TREADY, FFTOUT_TDATA, 
  FFTOUT_TKEEP, FFTOUT_TLAST)
/* synthesis syn_black_box black_box_pad_pin="ap_clk,ap_rst_n,FFTIN_TVALID,FFTIN_TREADY,FFTIN_TDATA[63:0],FFTIN_TKEEP[7:0],FFTIN_TLAST[0:0],FFTOUT_TVALID,FFTOUT_TREADY,FFTOUT_TDATA[63:0],FFTOUT_TKEEP[7:0],FFTOUT_TLAST[0:0]" */;
  input ap_clk;
  input ap_rst_n;
  input FFTIN_TVALID;
  output FFTIN_TREADY;
  input [63:0]FFTIN_TDATA;
  input [7:0]FFTIN_TKEEP;
  input [0:0]FFTIN_TLAST;
  output FFTOUT_TVALID;
  input FFTOUT_TREADY;
  output [63:0]FFTOUT_TDATA;
  output [7:0]FFTOUT_TKEEP;
  output [0:0]FFTOUT_TLAST;
endmodule
