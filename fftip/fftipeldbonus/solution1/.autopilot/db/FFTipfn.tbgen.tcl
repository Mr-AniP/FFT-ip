set moduleName FFTipfn
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_none
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {FFTipfn}
set C_modelType { void 0 }
set C_modelArgList {
	{ FFTIN_V_data int 64 regular {axi_s 0 volatile  { FFTIN Data } }  }
	{ FFTIN_V_last_V int 1 regular {axi_s 0 volatile  { FFTIN Last } }  }
	{ FFTIN_V_keep_V int 8 regular {axi_s 0 volatile  { FFTIN Keep } }  }
	{ FFTOUT_V_data int 64 regular {axi_s 1 volatile  { FFTOUT Data } }  }
	{ FFTOUT_V_last_V int 1 regular {axi_s 1 volatile  { FFTOUT Last } }  }
	{ FFTOUT_V_keep_V int 8 regular {axi_s 1 volatile  { FFTOUT Keep } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "FFTIN_V_data", "interface" : "axis", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "FFTIN.V.data._M_real","cData": "complex","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]},{"low":32,"up":63,"cElement": [{"cName": "FFTIN.V.data._M_imag","cData": "complex","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "FFTIN_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "FFTIN.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "FFTIN_V_keep_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "FFTIN.V.keep.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "FFTOUT_V_data", "interface" : "axis", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "FFTOUT.V.data._M_real","cData": "complex","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]},{"low":32,"up":63,"cElement": [{"cName": "FFTOUT.V.data._M_imag","cData": "complex","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "FFTOUT_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "FFTOUT.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "FFTOUT_V_keep_V", "interface" : "axis", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "FFTOUT.V.keep.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 12
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ FFTIN_TDATA sc_in sc_lv 64 signal 0 } 
	{ FFTIN_TVALID sc_in sc_logic 1 invld 2 } 
	{ FFTIN_TREADY sc_out sc_logic 1 inacc 2 } 
	{ FFTIN_TLAST sc_in sc_lv 1 signal 1 } 
	{ FFTIN_TKEEP sc_in sc_lv 8 signal 2 } 
	{ FFTOUT_TDATA sc_out sc_lv 64 signal 3 } 
	{ FFTOUT_TVALID sc_out sc_logic 1 outvld 5 } 
	{ FFTOUT_TREADY sc_in sc_logic 1 outacc 3 } 
	{ FFTOUT_TLAST sc_out sc_lv 1 signal 4 } 
	{ FFTOUT_TKEEP sc_out sc_lv 8 signal 5 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "FFTIN_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "FFTIN_V_data", "role": "default" }} , 
 	{ "name": "FFTIN_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "FFTIN_V_keep_V", "role": "default" }} , 
 	{ "name": "FFTIN_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "FFTIN_V_keep_V", "role": "default" }} , 
 	{ "name": "FFTIN_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "FFTIN_V_last_V", "role": "default" }} , 
 	{ "name": "FFTIN_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "FFTIN_V_keep_V", "role": "default" }} , 
 	{ "name": "FFTOUT_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "FFTOUT_V_data", "role": "default" }} , 
 	{ "name": "FFTOUT_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "FFTOUT_V_keep_V", "role": "default" }} , 
 	{ "name": "FFTOUT_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "FFTOUT_V_data", "role": "default" }} , 
 	{ "name": "FFTOUT_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "FFTOUT_V_last_V", "role": "default" }} , 
 	{ "name": "FFTOUT_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "FFTOUT_V_keep_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"],
		"CDFG" : "FFTipfn",
		"Protocol" : "ap_ctrl_none",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "FFTIN_V_data", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "FFTIN_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "FFTIN_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "FFTIN_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "FFTOUT_V_data", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "FFTOUT_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "FFTOUT_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "FFTOUT_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "W_real", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "W_imag", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.W_real_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.W_imag_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.tempout_R_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.tempout_I_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTIn_R_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTIn_I_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_faddfsub_bkb_U1", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_faddfsub_bkb_U2", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_fmul_32nscud_U3", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_fmul_32nscud_U4", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_fmul_32nscud_U5", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_fmul_32nscud_U6", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.FFTipfn_mul_mul_1dEe_U7", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	FFTipfn {
		FFTIN_V_data {Type I LastRead 1 FirstWrite -1}
		FFTIN_V_last_V {Type I LastRead 1 FirstWrite -1}
		FFTIN_V_keep_V {Type I LastRead 1 FirstWrite -1}
		FFTOUT_V_data {Type O LastRead -1 FirstWrite 7}
		FFTOUT_V_last_V {Type O LastRead -1 FirstWrite 7}
		FFTOUT_V_keep_V {Type O LastRead -1 FirstWrite 7}
		W_real {Type I LastRead -1 FirstWrite -1}
		W_imag {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
]}

set Spec2ImplPortList { 
	FFTIN_V_data { axis {  { FFTIN_TDATA in_data 0 64 } } }
	FFTIN_V_last_V { axis {  { FFTIN_TLAST in_data 0 1 } } }
	FFTIN_V_keep_V { axis {  { FFTIN_TVALID in_vld 0 1 }  { FFTIN_TREADY in_acc 1 1 }  { FFTIN_TKEEP in_data 0 8 } } }
	FFTOUT_V_data { axis {  { FFTOUT_TDATA out_data 1 64 }  { FFTOUT_TREADY out_acc 0 1 } } }
	FFTOUT_V_last_V { axis {  { FFTOUT_TLAST out_data 1 1 } } }
	FFTOUT_V_keep_V { axis {  { FFTOUT_TVALID out_vld 1 1 }  { FFTOUT_TKEEP out_data 1 8 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
