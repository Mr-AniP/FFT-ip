-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
-- Date        : Wed May 24 19:46:45 2023
-- Host        : SHANNON-PC1 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top design_1_FFTipfn_0_0 -prefix
--               design_1_FFTipfn_0_0_ design_1_FFTipfn_0_1_stub.vhdl
-- Design      : design_1_FFTipfn_0_1
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_FFTipfn_0_0 is
  Port ( 
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    FFTIN_TVALID : in STD_LOGIC;
    FFTIN_TREADY : out STD_LOGIC;
    FFTIN_TDATA : in STD_LOGIC_VECTOR ( 63 downto 0 );
    FFTIN_TKEEP : in STD_LOGIC_VECTOR ( 7 downto 0 );
    FFTIN_TLAST : in STD_LOGIC_VECTOR ( 0 to 0 );
    FFTOUT_TVALID : out STD_LOGIC;
    FFTOUT_TREADY : in STD_LOGIC;
    FFTOUT_TDATA : out STD_LOGIC_VECTOR ( 63 downto 0 );
    FFTOUT_TKEEP : out STD_LOGIC_VECTOR ( 7 downto 0 );
    FFTOUT_TLAST : out STD_LOGIC_VECTOR ( 0 to 0 )
  );

end design_1_FFTipfn_0_0;

architecture stub of design_1_FFTipfn_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "ap_clk,ap_rst_n,FFTIN_TVALID,FFTIN_TREADY,FFTIN_TDATA[63:0],FFTIN_TKEEP[7:0],FFTIN_TLAST[0:0],FFTOUT_TVALID,FFTOUT_TREADY,FFTOUT_TDATA[63:0],FFTOUT_TKEEP[7:0],FFTOUT_TLAST[0:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "FFTipfn,Vivado 2019.1";
begin
end;
