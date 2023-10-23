`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.11.2022 09:10:12
// Design Name: 
// Module Name: fft_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module fft_top(
  input aclk,
  input areset,
  
  input [31:0]data_in,
  input valid_in,
  input last_in,
  output ready_in,
  
  output [31:0]data_out,
  output valid_out,
  input ready_out,
  output last_out,
  
  input [7:0]config_data,
  input config_ready,
  input config_valid
  );
  wire event_frame_started,                  // output wire event_frame_started
  event_tlast_unexpected,            // output wire event_tlast_unexpected
  event_tlast_missing,                  // output wire event_tlast_missing
  event_status_channel_halt,      // output wire event_status_channel_halt
  event_data_in_channel_halt,    // output wire event_data_in_channel_halt
  event_data_out_channel_halt;
  wire[63:0] fft_in;
  wire[63:0] fft_out;
  assign fft_in[31:0]=data_in;
  assign fft_in[63:32]=32'd0;
  xfft_0 your_instance_name (
  .aclk(aclk),
  .aresetn(areset),                                                 // input wire aclk
  .s_axis_config_tdata(config_data),                  // input wire [7 : 0] s_axis_config_tdata
  .s_axis_config_tvalid(config_valid),                // input wire s_axis_config_tvalid
  .s_axis_config_tready(config_ready),                // output wire s_axis_config_tready
  .s_axis_data_tdata(fft_in),                      // input wire [63 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(valid_in),                    // input wire s_axis_data_tvalid
  .s_axis_data_tready(ready_in),                    // output wire s_axis_data_tready
  .s_axis_data_tlast(last_in),                      // input wire s_axis_data_tlast
  .m_axis_data_tdata(fft_out),                      // output wire [63 : 0] m_axis_data_tdata
  .m_axis_data_tvalid(valid_out),                    // output wire m_axis_data_tvalid
  .m_axis_data_tready(ready_out),                    // input wire m_axis_data_tready
  .m_axis_data_tlast(last_out),                      // output wire m_axis_data_tlast
  .event_frame_started(event_frame_started),                  // output wire event_frame_started
  .event_tlast_unexpected(event_tlast_unexpected),            // output wire event_tlast_unexpected
  .event_tlast_missing(event_tlast_missing),                  // output wire event_tlast_missing
  .event_status_channel_halt(event_status_channel_halt),      // output wire event_status_channel_halt
  .event_data_in_channel_halt(event_data_in_channel_halt),    // output wire event_data_in_channel_halt
  .event_data_out_channel_halt(event_data_out_channel_halt)  // output wire event_data_out_channel_halt
  );
  assign data_out=fft_out[31:0];
endmodule
