// (c) Copyright 1995-2023 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:hls:FFTipfn:1.1
// IP Revision: 1

(* X_CORE_INFO = "FFTipfn,Vivado 2019.1" *)
(* CHECK_LICENSE_TYPE = "design_1_FFTipfn_0_0,FFTipfn,{}" *)
(* CORE_GENERATION_INFO = "design_1_FFTipfn_0_0,FFTipfn,{x_ipProduct=Vivado 2019.1,x_ipVendor=xilinx.com,x_ipLibrary=hls,x_ipName=FFTipfn,x_ipVersion=1.1,x_ipCoreRevision=1,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED}" *)
(* IP_DEFINITION_SOURCE = "HLS" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module design_1_FFTipfn_0_0 (
  ap_clk,
  ap_rst_n,
  FFTIN_TVALID,
  FFTIN_TREADY,
  FFTIN_TDATA,
  FFTIN_TKEEP,
  FFTIN_TLAST,
  FFTOUT_TVALID,
  FFTOUT_TREADY,
  FFTOUT_TDATA,
  FFTOUT_TKEEP,
  FFTOUT_TLAST
);

(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF FFTIN:FFTOUT, ASSOCIATED_RESET ap_rst_n, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 ap_clk CLK" *)
input wire ap_clk;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 ap_rst_n RST" *)
input wire ap_rst_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTIN TVALID" *)
input wire FFTIN_TVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTIN TREADY" *)
output wire FFTIN_TREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTIN TDATA" *)
input wire [63 : 0] FFTIN_TDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTIN TKEEP" *)
input wire [7 : 0] FFTIN_TKEEP;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME FFTIN, TDATA_NUM_BYTES 8, TUSER_WIDTH 0, LAYERED_METADATA undef, TDEST_WIDTH 0, TID_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTIN TLAST" *)
input wire [0 : 0] FFTIN_TLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTOUT TVALID" *)
output wire FFTOUT_TVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTOUT TREADY" *)
input wire FFTOUT_TREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTOUT TDATA" *)
output wire [63 : 0] FFTOUT_TDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTOUT TKEEP" *)
output wire [7 : 0] FFTOUT_TKEEP;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME FFTOUT, TDATA_NUM_BYTES 8, TUSER_WIDTH 0, TDEST_WIDTH 0, TID_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 FFTOUT TLAST" *)
output wire [0 : 0] FFTOUT_TLAST;

  FFTipfn inst (
    .ap_clk(ap_clk),
    .ap_rst_n(ap_rst_n),
    .FFTIN_TVALID(FFTIN_TVALID),
    .FFTIN_TREADY(FFTIN_TREADY),
    .FFTIN_TDATA(FFTIN_TDATA),
    .FFTIN_TKEEP(FFTIN_TKEEP),
    .FFTIN_TLAST(FFTIN_TLAST),
    .FFTOUT_TVALID(FFTOUT_TVALID),
    .FFTOUT_TREADY(FFTOUT_TREADY),
    .FFTOUT_TDATA(FFTOUT_TDATA),
    .FFTOUT_TKEEP(FFTOUT_TKEEP),
    .FFTOUT_TLAST(FFTOUT_TLAST)
  );
endmodule
