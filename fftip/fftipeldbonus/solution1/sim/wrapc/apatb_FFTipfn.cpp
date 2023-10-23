// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->
    typedef struct com {
        std::complex<float > data;
        ap_uint<1> last;
        ap_uint<8> keep;
       } com;



// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "FFTIN_V_data"
#define AUTOTB_TVIN_FFTIN_V_data  "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_data.dat"
#define WRAPC_STREAM_SIZE_IN_FFTIN_V_data  "../tv/stream_size/stream_size_in_FFTIN_V_data.dat"
#define WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data  "../tv/stream_size/stream_ingress_status_FFTIN_V_data.dat"
// wrapc file define: "FFTIN_V_last_V"
#define AUTOTB_TVIN_FFTIN_V_last_V  "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_FFTIN_V_last_V  "../tv/stream_size/stream_size_in_FFTIN_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V  "../tv/stream_size/stream_ingress_status_FFTIN_V_last_V.dat"
// wrapc file define: "FFTIN_V_keep_V"
#define AUTOTB_TVIN_FFTIN_V_keep_V  "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_FFTIN_V_keep_V  "../tv/stream_size/stream_size_in_FFTIN_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V  "../tv/stream_size/stream_ingress_status_FFTIN_V_keep_V.dat"
// wrapc file define: "FFTOUT_V_data"
#define AUTOTB_TVOUT_FFTOUT_V_data  "../tv/cdatafile/c.FFTipfn.autotvout_FFTOUT_V_data.dat"
#define AUTOTB_TVIN_FFTOUT_V_data  "../tv/cdatafile/c.FFTipfn.autotvin_FFTOUT_V_data.dat"
#define WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data  "../tv/stream_size/stream_size_out_FFTOUT_V_data.dat"
#define WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_data  "../tv/stream_size/stream_egress_status_FFTOUT_V_data.dat"
// wrapc file define: "FFTOUT_V_last_V"
#define AUTOTB_TVOUT_FFTOUT_V_last_V  "../tv/cdatafile/c.FFTipfn.autotvout_FFTOUT_V_last_V.dat"
#define AUTOTB_TVIN_FFTOUT_V_last_V  "../tv/cdatafile/c.FFTipfn.autotvin_FFTOUT_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_FFTOUT_V_last_V  "../tv/stream_size/stream_size_out_FFTOUT_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_last_V  "../tv/stream_size/stream_egress_status_FFTOUT_V_last_V.dat"
// wrapc file define: "FFTOUT_V_keep_V"
#define AUTOTB_TVOUT_FFTOUT_V_keep_V  "../tv/cdatafile/c.FFTipfn.autotvout_FFTOUT_V_keep_V.dat"
#define AUTOTB_TVIN_FFTOUT_V_keep_V  "../tv/cdatafile/c.FFTipfn.autotvin_FFTOUT_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_FFTOUT_V_keep_V  "../tv/stream_size/stream_size_out_FFTOUT_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_keep_V  "../tv/stream_size/stream_egress_status_FFTOUT_V_keep_V.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "FFTOUT_V_data"
#define AUTOTB_TVOUT_PC_FFTOUT_V_data  "../tv/rtldatafile/rtl.FFTipfn.autotvout_FFTOUT_V_data.dat"
// tvout file define: "FFTOUT_V_last_V"
#define AUTOTB_TVOUT_PC_FFTOUT_V_last_V  "../tv/rtldatafile/rtl.FFTipfn.autotvout_FFTOUT_V_last_V.dat"
// tvout file define: "FFTOUT_V_keep_V"
#define AUTOTB_TVOUT_PC_FFTOUT_V_keep_V  "../tv/rtldatafile/rtl.FFTipfn.autotvout_FFTOUT_V_keep_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			FFTIN_V_data_depth = 0;
			FFTIN_V_last_V_depth = 0;
			FFTIN_V_keep_V_depth = 0;
			FFTOUT_V_data_depth = 0;
			FFTOUT_V_last_V_depth = 0;
			FFTOUT_V_keep_V_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{FFTIN_V_data " << FFTIN_V_data_depth << "}\n";
			total_list << "{FFTIN_V_last_V " << FFTIN_V_last_V_depth << "}\n";
			total_list << "{FFTIN_V_keep_V " << FFTIN_V_keep_V_depth << "}\n";
			total_list << "{FFTOUT_V_data " << FFTOUT_V_data_depth << "}\n";
			total_list << "{FFTOUT_V_last_V " << FFTOUT_V_last_V_depth << "}\n";
			total_list << "{FFTOUT_V_keep_V " << FFTOUT_V_keep_V_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int FFTIN_V_data_depth;
		int FFTIN_V_last_V_depth;
		int FFTIN_V_keep_V_depth;
		int FFTOUT_V_data_depth;
		int FFTOUT_V_last_V_depth;
		int FFTOUT_V_keep_V_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void FFTipfn (
hls::stream<com > (&FFTIN),
hls::stream<com > (&FFTOUT));

void AESL_WRAP_FFTipfn (
hls::stream<com > (&FFTIN),
hls::stream<com > (&FFTOUT))
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// pop stream input: "FFTIN"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, AESL_token); // pop_size
			int aesl_tmp_1 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_1; i++)
			{
				FFTIN.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "FFTOUT"
		std::vector<com > aesl_tmp_3;
		int aesl_tmp_4;
		int aesl_tmp_5 = 0;

		// read output stream size: "FFTOUT"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, AESL_token); // pop_size
			aesl_tmp_4 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, AESL_token); // [[/transaction]]
		}

		// output port post check: "FFTOUT_V_data"
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_data, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_data, AESL_token); // data

			std::vector<sc_bv<64> > FFTOUT_V_data_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					FFTOUT_V_data_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_data, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_FFTOUT_V_data))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					com tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: FFTOUT_V_data
				{
					// bitslice(31, 0)
					// {
						// celement: FFTOUT.V.data._M_real(31, 0)
						// {
							sc_lv<32>* FFTOUT_V_data__M_real_lv0_0_0_1_lv1_0_0_1 = new sc_lv<32>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }
					// bitslice(63, 32)
					// {
						// celement: FFTOUT.V.data._M_imag(31, 0)
						// {
							sc_lv<32>* FFTOUT_V_data__M_imag_lv0_0_0_1_lv1_0_0_1 = new sc_lv<32>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.data._M_real(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										FFTOUT_V_data__M_real_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(31, 0) = sc_bv<32>(FFTOUT_V_data_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}
					// bitslice(63, 32)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.data._M_imag(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										FFTOUT_V_data__M_imag_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(31, 0) = sc_bv<32>(FFTOUT_V_data_pc_buffer[hls_map_index].range(63, 32));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
    float wrap_real_FFTOUT_V_data__M_real;
						// celement: FFTOUT.V.data._M_real(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].data.real()
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].data
									// output_left_conversion : *(int*)&wrap_real_FFTOUT_V_data__M_real
									// output_type_conversion : (FFTOUT_V_data__M_real_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64()
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										wrap_real_FFTOUT_V_data__M_real = aesl_tmp_3[i_0].data.real();
										*(int*)&wrap_real_FFTOUT_V_data__M_real = (FFTOUT_V_data__M_real_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64();
										aesl_tmp_3[i_0].data.real(wrap_real_FFTOUT_V_data__M_real);
										hls_map_index++;
									}
								}
							}
						}
					}
					// bitslice(63, 32)
					{
						int hls_map_index = 0;
    float wrap_imag_FFTOUT_V_data__M_imag;
						// celement: FFTOUT.V.data._M_imag(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].data.imag()
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].data
									// output_left_conversion : *(int*)&wrap_imag_FFTOUT_V_data__M_imag
									// output_type_conversion : (FFTOUT_V_data__M_imag_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64()
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										wrap_imag_FFTOUT_V_data__M_imag = aesl_tmp_3[i_0].data.imag();
										*(int*)&wrap_imag_FFTOUT_V_data__M_imag = (FFTOUT_V_data__M_imag_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64();
										aesl_tmp_3[i_0].data.imag(wrap_imag_FFTOUT_V_data__M_imag);
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "FFTOUT_V_last_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_last_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_last_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_last_V, AESL_token); // data

			std::vector<sc_bv<1> > FFTOUT_V_last_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_last_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_last_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					FFTOUT_V_last_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_last_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_FFTOUT_V_last_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					com tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: FFTOUT_V_last_V
				{
					// bitslice(0, 0)
					// {
						// celement: FFTOUT.V.last.V(0, 0)
						// {
							sc_lv<1>* FFTOUT_V_last_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<1>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.last.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
									{
										FFTOUT_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(0, 0) = sc_bv<1>(FFTOUT_V_last_V_pc_buffer[hls_map_index].range(0, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.last.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].last
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].last
									// output_left_conversion : aesl_tmp_3[i_0].last
									// output_type_conversion : (FFTOUT_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].last = (FFTOUT_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "FFTOUT_V_keep_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_keep_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_keep_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_keep_V, AESL_token); // data

			std::vector<sc_bv<8> > FFTOUT_V_keep_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_keep_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'FFTOUT_V_keep_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					FFTOUT_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_FFTOUT_V_keep_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_FFTOUT_V_keep_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					com tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: FFTOUT_V_keep_V
				{
					// bitslice(7, 0)
					// {
						// celement: FFTOUT.V.keep.V(7, 0)
						// {
							sc_lv<8>* FFTOUT_V_keep_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<8>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.keep.V(7, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
									{
										FFTOUT_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(7, 0) = sc_bv<8>(FFTOUT_V_keep_V_pc_buffer[hls_map_index].range(7, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: FFTOUT.V.keep.V(7, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].keep
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].keep
									// output_left_conversion : aesl_tmp_3[i_0].keep
									// output_type_conversion : (FFTOUT_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].keep = (FFTOUT_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "FFTOUT"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			FFTOUT.write(aesl_tmp_3[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "FFTIN_V_data"
		char* tvin_FFTIN_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTIN_V_data);
		char* wrapc_stream_size_in_FFTIN_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_FFTIN_V_data);
		char* wrapc_stream_ingress_status_FFTIN_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data);

		// "FFTIN_V_last_V"
		char* tvin_FFTIN_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTIN_V_last_V);
		char* wrapc_stream_size_in_FFTIN_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_FFTIN_V_last_V);
		char* wrapc_stream_ingress_status_FFTIN_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V);

		// "FFTIN_V_keep_V"
		char* tvin_FFTIN_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTIN_V_keep_V);
		char* wrapc_stream_size_in_FFTIN_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_FFTIN_V_keep_V);
		char* wrapc_stream_ingress_status_FFTIN_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V);

		// "FFTOUT_V_data"
		char* tvin_FFTOUT_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTOUT_V_data);
		char* tvout_FFTOUT_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_FFTOUT_V_data);
		char* wrapc_stream_size_out_FFTOUT_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data);
		char* wrapc_stream_egress_status_FFTOUT_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_data);

		// "FFTOUT_V_last_V"
		char* tvin_FFTOUT_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTOUT_V_last_V);
		char* tvout_FFTOUT_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_FFTOUT_V_last_V);
		char* wrapc_stream_size_out_FFTOUT_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_last_V);
		char* wrapc_stream_egress_status_FFTOUT_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_last_V);

		// "FFTOUT_V_keep_V"
		char* tvin_FFTOUT_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_FFTOUT_V_keep_V);
		char* tvout_FFTOUT_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_FFTOUT_V_keep_V);
		char* wrapc_stream_size_out_FFTOUT_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_keep_V);
		char* wrapc_stream_egress_status_FFTOUT_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_FFTOUT_V_keep_V);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "FFTIN"
		std::vector<com > aesl_tmp_0;
		int aesl_tmp_1 = 0;
		while (!FFTIN.empty())
		{
			aesl_tmp_0.push_back(FFTIN.read());
			aesl_tmp_1++;
		}

		// dump stream tvin: "FFTOUT"
		std::vector<com > aesl_tmp_3;
		int aesl_tmp_4 = 0;
		while (!FFTOUT.empty())
		{
			aesl_tmp_3.push_back(FFTOUT.read());
			aesl_tmp_4++;
		}

		// push back input stream: "FFTIN"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			FFTIN.write(aesl_tmp_0[i]);
		}

		// push back input stream: "FFTOUT"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			FFTOUT.write(aesl_tmp_3[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		FFTipfn(FFTIN, FFTOUT);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "FFTIN"
		int aesl_tmp_2 = FFTIN.size();

		// pop output stream: "FFTOUT"
		int aesl_tmp_5 = aesl_tmp_4;
		aesl_tmp_4 = 0;
     aesl_tmp_3.clear();
		while (!FFTOUT.empty())
		{
			aesl_tmp_3.push_back(FFTOUT.read());
			aesl_tmp_4++;
		}

		// [[transaction]]
		sprintf(tvin_FFTIN_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_data, tvin_FFTIN_V_data);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, tvin_FFTIN_V_data);

		sc_bv<64>* FFTIN_V_data_tvin_wrapc_buffer = new sc_bv<64>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: FFTIN_V_data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
    float wrap_real_FFTIN_V_data__M_real;
				// celement: FFTIN.V.data._M_real(31, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].data.real()
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].data
							// regulate_c_name       : FFTIN_V_data__M_real
							// input_type_conversion : *(int*)&wrap_real_FFTIN_V_data__M_real
							if (&(aesl_tmp_0[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> FFTIN_V_data__M_real_tmp_mem;
                                 		       wrap_real_FFTIN_V_data__M_real = aesl_tmp_0[i_0].data.real();
								FFTIN_V_data__M_real_tmp_mem = *(int*)&wrap_real_FFTIN_V_data__M_real;
								FFTIN_V_data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = FFTIN_V_data__M_real_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
			// bitslice(63, 32)
			{
				int hls_map_index = 0;
    float wrap_imag_FFTIN_V_data__M_imag;
				// celement: FFTIN.V.data._M_imag(31, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].data.imag()
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].data
							// regulate_c_name       : FFTIN_V_data__M_imag
							// input_type_conversion : *(int*)&wrap_imag_FFTIN_V_data__M_imag
							if (&(aesl_tmp_0[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> FFTIN_V_data__M_imag_tmp_mem;
                                 		       wrap_imag_FFTIN_V_data__M_imag = aesl_tmp_0[i_0].data.imag();
								FFTIN_V_data__M_imag_tmp_mem = *(int*)&wrap_imag_FFTIN_V_data__M_imag;
								FFTIN_V_data_tvin_wrapc_buffer[hls_map_index].range(63, 32) = FFTIN_V_data__M_imag_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_FFTIN_V_data, "%s\n", (FFTIN_V_data_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_FFTIN_V_data, tvin_FFTIN_V_data);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_FFTIN_V_data = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, stream_ingress_size_FFTIN_V_data.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_FFTIN_V_data--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, stream_ingress_size_FFTIN_V_data.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_FFTIN_V_data = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, stream_ingress_size_FFTIN_V_data.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.FFTIN_V_data_depth);
		sprintf(tvin_FFTIN_V_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_data, tvin_FFTIN_V_data);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_data, tvin_FFTIN_V_data);

		// release memory allocation
		delete [] FFTIN_V_data_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_FFTIN_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, wrapc_stream_size_in_FFTIN_V_data);
		sprintf(wrapc_stream_size_in_FFTIN_V_data, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, wrapc_stream_size_in_FFTIN_V_data);
		sprintf(wrapc_stream_size_in_FFTIN_V_data, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_data, wrapc_stream_size_in_FFTIN_V_data);

		// [[transaction]]
		sprintf(tvin_FFTIN_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_last_V, tvin_FFTIN_V_last_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, tvin_FFTIN_V_last_V);

		sc_bv<1>* FFTIN_V_last_V_tvin_wrapc_buffer = new sc_bv<1>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: FFTIN_V_last_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: FFTIN.V.last.V(0, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].last
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].last
							// regulate_c_name       : FFTIN_V_last_V
							// input_type_conversion : (aesl_tmp_0[i_0].last).to_string(2).c_str()
							if (&(aesl_tmp_0[0].last) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> FFTIN_V_last_V_tmp_mem;
								FFTIN_V_last_V_tmp_mem = (aesl_tmp_0[i_0].last).to_string(2).c_str();
								FFTIN_V_last_V_tvin_wrapc_buffer[hls_map_index].range(0, 0) = FFTIN_V_last_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_FFTIN_V_last_V, "%s\n", (FFTIN_V_last_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_FFTIN_V_last_V, tvin_FFTIN_V_last_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_FFTIN_V_last_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, stream_ingress_size_FFTIN_V_last_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_FFTIN_V_last_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, stream_ingress_size_FFTIN_V_last_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_FFTIN_V_last_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, stream_ingress_size_FFTIN_V_last_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.FFTIN_V_last_V_depth);
		sprintf(tvin_FFTIN_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_last_V, tvin_FFTIN_V_last_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_last_V, tvin_FFTIN_V_last_V);

		// release memory allocation
		delete [] FFTIN_V_last_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_FFTIN_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_last_V, wrapc_stream_size_in_FFTIN_V_last_V);
		sprintf(wrapc_stream_size_in_FFTIN_V_last_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_last_V, wrapc_stream_size_in_FFTIN_V_last_V);
		sprintf(wrapc_stream_size_in_FFTIN_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_last_V, wrapc_stream_size_in_FFTIN_V_last_V);

		// [[transaction]]
		sprintf(tvin_FFTIN_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_keep_V, tvin_FFTIN_V_keep_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, tvin_FFTIN_V_keep_V);

		sc_bv<8>* FFTIN_V_keep_V_tvin_wrapc_buffer = new sc_bv<8>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: FFTIN_V_keep_V
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: FFTIN.V.keep.V(7, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].keep
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].keep
							// regulate_c_name       : FFTIN_V_keep_V
							// input_type_conversion : (aesl_tmp_0[i_0].keep).to_string(2).c_str()
							if (&(aesl_tmp_0[0].keep) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> FFTIN_V_keep_V_tmp_mem;
								FFTIN_V_keep_V_tmp_mem = (aesl_tmp_0[i_0].keep).to_string(2).c_str();
								FFTIN_V_keep_V_tvin_wrapc_buffer[hls_map_index].range(7, 0) = FFTIN_V_keep_V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_FFTIN_V_keep_V, "%s\n", (FFTIN_V_keep_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_FFTIN_V_keep_V, tvin_FFTIN_V_keep_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_FFTIN_V_keep_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, stream_ingress_size_FFTIN_V_keep_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_FFTIN_V_keep_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, stream_ingress_size_FFTIN_V_keep_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_FFTIN_V_keep_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, stream_ingress_size_FFTIN_V_keep_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.FFTIN_V_keep_V_depth);
		sprintf(tvin_FFTIN_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_FFTIN_V_keep_V, tvin_FFTIN_V_keep_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_FFTIN_V_keep_V, tvin_FFTIN_V_keep_V);

		// release memory allocation
		delete [] FFTIN_V_keep_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_FFTIN_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_keep_V, wrapc_stream_size_in_FFTIN_V_keep_V);
		sprintf(wrapc_stream_size_in_FFTIN_V_keep_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_keep_V, wrapc_stream_size_in_FFTIN_V_keep_V);
		sprintf(wrapc_stream_size_in_FFTIN_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_FFTIN_V_keep_V, wrapc_stream_size_in_FFTIN_V_keep_V);

		// [[transaction]]
		sprintf(tvout_FFTOUT_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_data, tvout_FFTOUT_V_data);

		sc_bv<64>* FFTOUT_V_data_tvout_wrapc_buffer = new sc_bv<64>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: FFTOUT_V_data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
    float wrap_real_FFTOUT_V_data__M_real;
				// celement: FFTOUT.V.data._M_real(31, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].data.real()
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].data
							// regulate_c_name       : FFTOUT_V_data__M_real
							// input_type_conversion : *(int*)&wrap_real_FFTOUT_V_data__M_real
							if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> FFTOUT_V_data__M_real_tmp_mem;
                                 		       wrap_real_FFTOUT_V_data__M_real = aesl_tmp_3[i_0].data.real();
								FFTOUT_V_data__M_real_tmp_mem = *(int*)&wrap_real_FFTOUT_V_data__M_real;
								FFTOUT_V_data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = FFTOUT_V_data__M_real_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
			// bitslice(63, 32)
			{
				int hls_map_index = 0;
    float wrap_imag_FFTOUT_V_data__M_imag;
				// celement: FFTOUT.V.data._M_imag(31, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].data.imag()
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].data
							// regulate_c_name       : FFTOUT_V_data__M_imag
							// input_type_conversion : *(int*)&wrap_imag_FFTOUT_V_data__M_imag
							if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> FFTOUT_V_data__M_imag_tmp_mem;
                                 		       wrap_imag_FFTOUT_V_data__M_imag = aesl_tmp_3[i_0].data.imag();
								FFTOUT_V_data__M_imag_tmp_mem = *(int*)&wrap_imag_FFTOUT_V_data__M_imag;
								FFTOUT_V_data_tvout_wrapc_buffer[hls_map_index].range(63, 32) = FFTOUT_V_data__M_imag_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_FFTOUT_V_data, "%s\n", (FFTOUT_V_data_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_data, tvout_FFTOUT_V_data);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.FFTOUT_V_data_depth);
		sprintf(tvout_FFTOUT_V_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_data, tvout_FFTOUT_V_data);

		// release memory allocation
		delete [] FFTOUT_V_data_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_FFTOUT_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, wrapc_stream_size_out_FFTOUT_V_data);
		sprintf(wrapc_stream_size_out_FFTOUT_V_data, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, wrapc_stream_size_out_FFTOUT_V_data);
		sprintf(wrapc_stream_size_out_FFTOUT_V_data, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_data, wrapc_stream_size_out_FFTOUT_V_data);

		// [[transaction]]
		sprintf(tvout_FFTOUT_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_last_V, tvout_FFTOUT_V_last_V);

		sc_bv<1>* FFTOUT_V_last_V_tvout_wrapc_buffer = new sc_bv<1>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: FFTOUT_V_last_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: FFTOUT.V.last.V(0, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].last
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].last
							// regulate_c_name       : FFTOUT_V_last_V
							// input_type_conversion : (aesl_tmp_3[i_0].last).to_string(2).c_str()
							if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> FFTOUT_V_last_V_tmp_mem;
								FFTOUT_V_last_V_tmp_mem = (aesl_tmp_3[i_0].last).to_string(2).c_str();
								FFTOUT_V_last_V_tvout_wrapc_buffer[hls_map_index].range(0, 0) = FFTOUT_V_last_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_FFTOUT_V_last_V, "%s\n", (FFTOUT_V_last_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_last_V, tvout_FFTOUT_V_last_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.FFTOUT_V_last_V_depth);
		sprintf(tvout_FFTOUT_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_last_V, tvout_FFTOUT_V_last_V);

		// release memory allocation
		delete [] FFTOUT_V_last_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_FFTOUT_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_last_V, wrapc_stream_size_out_FFTOUT_V_last_V);
		sprintf(wrapc_stream_size_out_FFTOUT_V_last_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_last_V, wrapc_stream_size_out_FFTOUT_V_last_V);
		sprintf(wrapc_stream_size_out_FFTOUT_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_last_V, wrapc_stream_size_out_FFTOUT_V_last_V);

		// [[transaction]]
		sprintf(tvout_FFTOUT_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_keep_V, tvout_FFTOUT_V_keep_V);

		sc_bv<8>* FFTOUT_V_keep_V_tvout_wrapc_buffer = new sc_bv<8>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: FFTOUT_V_keep_V
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: FFTOUT.V.keep.V(7, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].keep
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].keep
							// regulate_c_name       : FFTOUT_V_keep_V
							// input_type_conversion : (aesl_tmp_3[i_0].keep).to_string(2).c_str()
							if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> FFTOUT_V_keep_V_tmp_mem;
								FFTOUT_V_keep_V_tmp_mem = (aesl_tmp_3[i_0].keep).to_string(2).c_str();
								FFTOUT_V_keep_V_tvout_wrapc_buffer[hls_map_index].range(7, 0) = FFTOUT_V_keep_V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_FFTOUT_V_keep_V, "%s\n", (FFTOUT_V_keep_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_keep_V, tvout_FFTOUT_V_keep_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.FFTOUT_V_keep_V_depth);
		sprintf(tvout_FFTOUT_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_FFTOUT_V_keep_V, tvout_FFTOUT_V_keep_V);

		// release memory allocation
		delete [] FFTOUT_V_keep_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_FFTOUT_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_keep_V, wrapc_stream_size_out_FFTOUT_V_keep_V);
		sprintf(wrapc_stream_size_out_FFTOUT_V_keep_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_keep_V, wrapc_stream_size_out_FFTOUT_V_keep_V);
		sprintf(wrapc_stream_size_out_FFTOUT_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_FFTOUT_V_keep_V, wrapc_stream_size_out_FFTOUT_V_keep_V);

		// push back output stream: "FFTOUT"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			FFTOUT.write(aesl_tmp_3[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "FFTIN_V_data"
		delete [] tvin_FFTIN_V_data;
		delete [] wrapc_stream_size_in_FFTIN_V_data;
		// release memory allocation: "FFTIN_V_last_V"
		delete [] tvin_FFTIN_V_last_V;
		delete [] wrapc_stream_size_in_FFTIN_V_last_V;
		// release memory allocation: "FFTIN_V_keep_V"
		delete [] tvin_FFTIN_V_keep_V;
		delete [] wrapc_stream_size_in_FFTIN_V_keep_V;
		// release memory allocation: "FFTOUT_V_data"
		delete [] tvout_FFTOUT_V_data;
		delete [] tvin_FFTOUT_V_data;
		delete [] wrapc_stream_size_out_FFTOUT_V_data;
		// release memory allocation: "FFTOUT_V_last_V"
		delete [] tvout_FFTOUT_V_last_V;
		delete [] tvin_FFTOUT_V_last_V;
		delete [] wrapc_stream_size_out_FFTOUT_V_last_V;
		// release memory allocation: "FFTOUT_V_keep_V"
		delete [] tvout_FFTOUT_V_keep_V;
		delete [] tvin_FFTOUT_V_keep_V;
		delete [] wrapc_stream_size_out_FFTOUT_V_keep_V;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

