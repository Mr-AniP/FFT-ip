vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xilinx_vip
vlib questa_lib/msim/xil_defaultlib
vlib questa_lib/msim/xpm
vlib questa_lib/msim/axi_infrastructure_v1_1_0
vlib questa_lib/msim/axi_vip_v1_1_5
vlib questa_lib/msim/processing_system7_vip_v1_0_7
vlib questa_lib/msim/lib_pkg_v1_0_2
vlib questa_lib/msim/fifo_generator_v13_2_4
vlib questa_lib/msim/lib_fifo_v1_0_13
vlib questa_lib/msim/lib_srl_fifo_v1_0_2
vlib questa_lib/msim/lib_cdc_v1_0_2
vlib questa_lib/msim/axi_datamover_v5_1_21
vlib questa_lib/msim/axi_sg_v4_1_12
vlib questa_lib/msim/axi_dma_v7_1_20
vlib questa_lib/msim/xlconstant_v1_1_6
vlib questa_lib/msim/proc_sys_reset_v5_0_13
vlib questa_lib/msim/smartconnect_v1_0
vlib questa_lib/msim/generic_baseblocks_v2_1_0
vlib questa_lib/msim/axi_register_slice_v2_1_19
vlib questa_lib/msim/axi_data_fifo_v2_1_18
vlib questa_lib/msim/axi_crossbar_v2_1_20
vlib questa_lib/msim/axi_protocol_converter_v2_1_19
vlib questa_lib/msim/xbip_utils_v3_0_10
vlib questa_lib/msim/axi_utils_v2_0_6
vlib questa_lib/msim/xbip_pipe_v3_0_6
vlib questa_lib/msim/xbip_dsp48_wrapper_v3_0_4
vlib questa_lib/msim/xbip_dsp48_addsub_v3_0_6
vlib questa_lib/msim/xbip_dsp48_multadd_v3_0_6
vlib questa_lib/msim/xbip_bram18k_v3_0_6
vlib questa_lib/msim/mult_gen_v12_0_15
vlib questa_lib/msim/floating_point_v7_1_8

vmap xilinx_vip questa_lib/msim/xilinx_vip
vmap xil_defaultlib questa_lib/msim/xil_defaultlib
vmap xpm questa_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 questa_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_5 questa_lib/msim/axi_vip_v1_1_5
vmap processing_system7_vip_v1_0_7 questa_lib/msim/processing_system7_vip_v1_0_7
vmap lib_pkg_v1_0_2 questa_lib/msim/lib_pkg_v1_0_2
vmap fifo_generator_v13_2_4 questa_lib/msim/fifo_generator_v13_2_4
vmap lib_fifo_v1_0_13 questa_lib/msim/lib_fifo_v1_0_13
vmap lib_srl_fifo_v1_0_2 questa_lib/msim/lib_srl_fifo_v1_0_2
vmap lib_cdc_v1_0_2 questa_lib/msim/lib_cdc_v1_0_2
vmap axi_datamover_v5_1_21 questa_lib/msim/axi_datamover_v5_1_21
vmap axi_sg_v4_1_12 questa_lib/msim/axi_sg_v4_1_12
vmap axi_dma_v7_1_20 questa_lib/msim/axi_dma_v7_1_20
vmap xlconstant_v1_1_6 questa_lib/msim/xlconstant_v1_1_6
vmap proc_sys_reset_v5_0_13 questa_lib/msim/proc_sys_reset_v5_0_13
vmap smartconnect_v1_0 questa_lib/msim/smartconnect_v1_0
vmap generic_baseblocks_v2_1_0 questa_lib/msim/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_19 questa_lib/msim/axi_register_slice_v2_1_19
vmap axi_data_fifo_v2_1_18 questa_lib/msim/axi_data_fifo_v2_1_18
vmap axi_crossbar_v2_1_20 questa_lib/msim/axi_crossbar_v2_1_20
vmap axi_protocol_converter_v2_1_19 questa_lib/msim/axi_protocol_converter_v2_1_19
vmap xbip_utils_v3_0_10 questa_lib/msim/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 questa_lib/msim/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 questa_lib/msim/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 questa_lib/msim/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 questa_lib/msim/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 questa_lib/msim/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 questa_lib/msim/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_15 questa_lib/msim/mult_gen_v12_0_15
vmap floating_point_v7_1_8 questa_lib/msim/floating_point_v7_1_8

vlog -work xilinx_vip -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"E:/xilinx/Vivado/2019.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"E:/xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"E:/xilinx/Vivado/2019.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"E:/xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -64 -93 \
"E:/xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_5 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/d4a8/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_7 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \

vcom -work lib_pkg_v1_0_2 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/0513/hdl/lib_pkg_v1_0_rfs.vhd" \

vlog -work fifo_generator_v13_2_4 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1f5a/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_4 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_4 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.v" \

vcom -work lib_fifo_v1_0_13 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/4dac/hdl/lib_fifo_v1_0_rfs.vhd" \

vcom -work lib_srl_fifo_v1_0_2 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/51ce/hdl/lib_srl_fifo_v1_0_rfs.vhd" \

vcom -work lib_cdc_v1_0_2 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work axi_datamover_v5_1_21 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/e644/hdl/axi_datamover_v5_1_vh_rfs.vhd" \

vcom -work axi_sg_v4_1_12 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/91f3/hdl/axi_sg_v4_1_rfs.vhd" \

vcom -work axi_dma_v7_1_20 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/260a/hdl/axi_dma_v7_1_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_1/ip/design_1_axi_dma_0_2/sim/design_1_axi_dma_0_2.vhd" \

vlog -work xlconstant_v1_1_6 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/66e7/hdl/xlconstant_v1_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_0/sim/bd_ae83_one_0.v" \

vcom -work proc_sys_reset_v5_0_13 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_1/sim/bd_ae83_psr_aclk_0.vhd" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/sc_util_v1_0_vl_rfs.sv" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c012/hdl/sc_switchboard_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_2/sim/bd_ae83_arsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_3/sim/bd_ae83_rsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_4/sim/bd_ae83_awsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_5/sim/bd_ae83_wsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_6/sim/bd_ae83_bsw_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_7/sim/bd_ae83_s00mmu_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_8/sim/bd_ae83_s00tr_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/7de4/hdl/sc_si_converter_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_9/sim/bd_ae83_s00sic_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_10/sim/bd_ae83_s00a2s_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_11/sim/bd_ae83_sarn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_12/sim/bd_ae83_srn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_13/sim/bd_ae83_s01mmu_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_14/sim/bd_ae83_s01tr_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_15/sim/bd_ae83_s01sic_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_16/sim/bd_ae83_s01a2s_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_17/sim/bd_ae83_sawn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_18/sim/bd_ae83_swn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_19/sim/bd_ae83_sbn_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_20/sim/bd_ae83_m00s2a_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_21/sim/bd_ae83_m00arn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_22/sim/bd_ae83_m00rn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_23/sim/bd_ae83_m00awn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_24/sim/bd_ae83_m00wn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_25/sim/bd_ae83_m00bn_0.sv" \

vlog -work smartconnect_v1_0 -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/ip/ip_26/sim/bd_ae83_m00e_0.sv" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_3/bd_0/sim/bd_ae83.v" \
"../../../bd/design_1/ip/design_1_axi_smc_3/sim/design_1_axi_smc_3.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_100M_3/sim/design_1_rst_ps7_0_100M_3.vhd" \

vlog -work generic_baseblocks_v2_1_0 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_19 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/4d88/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_data_fifo_v2_1_18 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/5b9c/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_20 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ace7/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \

vlog -work axi_protocol_converter_v2_1_19 -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c83a/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_1/ip/design_1_axi_dma_1_1/sim/design_1_axi_dma_1_1.vhd" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_0/sim/bd_68b9_one_0.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_1/sim/bd_68b9_psr_aclk_0.vhd" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_5 -L processing_system7_vip_v1_0_7 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_2/sim/bd_68b9_arsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_3/sim/bd_68b9_rsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_4/sim/bd_68b9_awsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_5/sim/bd_68b9_wsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_6/sim/bd_68b9_bsw_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_7/sim/bd_68b9_s00mmu_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_8/sim/bd_68b9_s00tr_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_9/sim/bd_68b9_s00sic_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_10/sim/bd_68b9_s00a2s_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_11/sim/bd_68b9_sarn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_12/sim/bd_68b9_srn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_13/sim/bd_68b9_s01mmu_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_14/sim/bd_68b9_s01tr_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_15/sim/bd_68b9_s01sic_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_16/sim/bd_68b9_s01a2s_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_17/sim/bd_68b9_sawn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_18/sim/bd_68b9_swn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_19/sim/bd_68b9_sbn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_20/sim/bd_68b9_m00s2a_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_21/sim/bd_68b9_m00arn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_22/sim/bd_68b9_m00rn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_23/sim/bd_68b9_m00awn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_24/sim/bd_68b9_m00wn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_25/sim/bd_68b9_m00bn_0.sv" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/ip/ip_26/sim/bd_68b9_m00e_0.sv" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/bd_0/sim/bd_68b9.v" \
"../../../bd/design_1/ip/design_1_axi_smc_1_1/sim/design_1_axi_smc_1_1.v" \

vcom -work xbip_utils_v3_0_10 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1123/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_15 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/d4d2/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_8 -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/83a3/hdl/floating_point_v7_1_vh_rfs.vhd" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_faddfsub_bkb.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_fmul_32nscud.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_mul_mul_1dEe.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_tempout_R.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_W_imag.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn_W_real.v" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/verilog/FFTipfn.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/ip/FFTipfn_ap_faddfsub_3_full_dsp_32.vhd" \
"../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/c75b/hdl/ip/FFTipfn_ap_fmul_2_max_dsp_32.vhd" \
"../../../bd/design_1/ip/design_1_FFTipfn_0_1/sim/design_1_FFTipfn_0_1.vhd" \
"../../../bd/design_1/ip/design_1_FFTipfn_1_1/sim/design_1_FFTipfn_1_1.vhd" \

vlog -work xil_defaultlib -64 "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/8c62/hdl" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/verilog" "+incdir+../../../../debugfft.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+E:/xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/design_1/sim/design_1.v" \

vlog -work xil_defaultlib \
"glbl.v"

