############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fftipeldbonus
set_top FFTipfn
add_files fftipeldbonus/fft.cpp
add_files fftipeldbonus/fft.h
add_files -tb fftipeldbonus/ffttb.cpp
open_solution "solution1"
set_part {xc7z020-clg484-1} -tool vivado
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog -use_netlist none -version 1.1.1 -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
#source "./fftipeldbonus/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog -version "1.1.1"
