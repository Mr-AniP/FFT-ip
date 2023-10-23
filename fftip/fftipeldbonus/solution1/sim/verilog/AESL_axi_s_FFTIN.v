// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps

`define TV_IN_FFTIN_TDATA "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_data.dat"
`define INGRESS_STATUS_FFTIN_TDATA "../tv/stream_size/stream_ingress_status_FFTIN_V_data.dat"
`define TV_IN_FFTIN_TLAST "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_last_V.dat"
`define INGRESS_STATUS_FFTIN_TLAST "../tv/stream_size/stream_ingress_status_FFTIN_V_last_V.dat"
`define TV_IN_FFTIN_TKEEP "../tv/cdatafile/c.FFTipfn.autotvin_FFTIN_V_keep_V.dat"
`define INGRESS_STATUS_FFTIN_TKEEP "../tv/stream_size/stream_ingress_status_FFTIN_V_keep_V.dat"

`define AUTOTB_TRANSACTION_NUM 1

module AESL_axi_s_FFTIN (
    input clk,
    input reset,
    output [64 - 1:0] TRAN_FFTIN_TDATA,
    output TRAN_FFTIN_TLAST,
    output [8 - 1:0] TRAN_FFTIN_TKEEP,
    output TRAN_FFTIN_TVALID,
    input TRAN_FFTIN_TREADY,
    input ready,
    input done,
    output [31:0] transaction);

    wire TRAN_FFTIN_TVALID_temp;
    wire FFTIN_TDATA_full;
    wire FFTIN_TDATA_empty;
    reg FFTIN_TDATA_write_en;
    reg [64 - 1:0] FFTIN_TDATA_write_data;
    reg FFTIN_TDATA_read_en;
    wire [64 - 1:0] FFTIN_TDATA_read_data;
    
    fifo #(1024, 64) fifo_FFTIN_TDATA (
        .reset(1'b0),
        .write_clock(clk),
        .write_en(FFTIN_TDATA_write_en),
        .write_data(FFTIN_TDATA_write_data),
        .read_clock(clk),
        .read_en(FFTIN_TDATA_read_en),
        .read_data(FFTIN_TDATA_read_data),
        .full(FFTIN_TDATA_full),
        .empty(FFTIN_TDATA_empty));
    
    always @ (*) begin
        FFTIN_TDATA_write_en <= 0;
        FFTIN_TDATA_read_en <= TRAN_FFTIN_TREADY & TRAN_FFTIN_TVALID;
    end
    
    assign TRAN_FFTIN_TDATA = FFTIN_TDATA_read_data;
    wire FFTIN_TLAST_full;
    wire FFTIN_TLAST_empty;
    reg FFTIN_TLAST_write_en;
    reg [1 - 1:0] FFTIN_TLAST_write_data;
    reg FFTIN_TLAST_read_en;
    wire [1 - 1:0] FFTIN_TLAST_read_data;
    
    fifo #(1024, 1) fifo_FFTIN_TLAST (
        .reset(1'b0),
        .write_clock(clk),
        .write_en(FFTIN_TLAST_write_en),
        .write_data(FFTIN_TLAST_write_data),
        .read_clock(clk),
        .read_en(FFTIN_TLAST_read_en),
        .read_data(FFTIN_TLAST_read_data),
        .full(FFTIN_TLAST_full),
        .empty(FFTIN_TLAST_empty));
    
    always @ (*) begin
        FFTIN_TLAST_write_en <= 0;
        FFTIN_TLAST_read_en <= TRAN_FFTIN_TREADY & TRAN_FFTIN_TVALID;
    end
    
    assign TRAN_FFTIN_TLAST = FFTIN_TLAST_read_data;
    wire FFTIN_TKEEP_full;
    wire FFTIN_TKEEP_empty;
    reg FFTIN_TKEEP_write_en;
    reg [8 - 1:0] FFTIN_TKEEP_write_data;
    reg FFTIN_TKEEP_read_en;
    wire [8 - 1:0] FFTIN_TKEEP_read_data;
    
    fifo #(1024, 8) fifo_FFTIN_TKEEP (
        .reset(1'b0),
        .write_clock(clk),
        .write_en(FFTIN_TKEEP_write_en),
        .write_data(FFTIN_TKEEP_write_data),
        .read_clock(clk),
        .read_en(FFTIN_TKEEP_read_en),
        .read_data(FFTIN_TKEEP_read_data),
        .full(FFTIN_TKEEP_full),
        .empty(FFTIN_TKEEP_empty));
    
    always @ (*) begin
        FFTIN_TKEEP_write_en <= 0;
        FFTIN_TKEEP_read_en <= TRAN_FFTIN_TREADY & TRAN_FFTIN_TVALID;
    end
    
    assign TRAN_FFTIN_TKEEP = FFTIN_TKEEP_read_data;
    assign TRAN_FFTIN_TVALID = TRAN_FFTIN_TVALID_temp;

    
    reg FFTIN_TDATA_valid = 0; // ingress buffer indicator: FFTIN_TDATA
    reg FFTIN_TLAST_valid = 0; // ingress buffer indicator: FFTIN_TLAST
    reg FFTIN_TKEEP_valid = 0; // ingress buffer indicator: FFTIN_TKEEP
    
    assign TRAN_FFTIN_TVALID_temp = ~(FFTIN_TDATA_empty || FFTIN_TLAST_empty || FFTIN_TKEEP_empty) || (FFTIN_TDATA_valid && FFTIN_TLAST_valid && FFTIN_TKEEP_valid);
    
    function is_blank_char(input [7:0] in_char);
        if (in_char == " " || in_char == "\011" || in_char == "\012" || in_char == "\015") begin
            is_blank_char = 1;
        end else begin
            is_blank_char = 0;
        end
    endfunction
    
    function [151:0] read_token(input integer fp);
        integer ret;
        begin
            read_token = "";
                    ret = 0;
                    ret = $fscanf(fp,"%s",read_token);
        end
    endfunction
    
    function [151:0] rm_0x(input [151:0] token);
        reg [151:0] token_tmp;
        integer i;
        begin
            token_tmp = "";
            for (i = 0; token[15:0] != "0x"; token = token >> 8) begin
                token_tmp = (token[7:0] << (8 * i)) | token_tmp;
                i = i + 1;
            end
            rm_0x = token_tmp;
        end
    endfunction
    
    reg [31:0] transaction_load_FFTIN_TDATA;
    
    assign transaction = transaction_load_FFTIN_TDATA;
    
    initial begin : AXI_stream_driver_FFTIN_TDATA
        integer fp;
        reg [151:0] token;
        reg [64 - 1:0] data;
        reg [151:0] data_integer;
        integer fp_ingress_status;
        reg [151:0] token_ingress_status;
        reg [31:0] ingress_status;
        reg [8 * 5:1] str;
        integer ret;
        
        transaction_load_FFTIN_TDATA = 0;
        fifo_FFTIN_TDATA.clear();
        wait (reset === 1);
        fp = $fopen(`TV_IN_FFTIN_TDATA, "r");
        if (fp == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `TV_IN_FFTIN_TDATA);
            $finish;
        end
        fp_ingress_status = $fopen(`INGRESS_STATUS_FFTIN_TDATA, "r");
        if (fp_ingress_status == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `INGRESS_STATUS_FFTIN_TDATA);
            $finish;
        end
        token = read_token(fp);
        token_ingress_status = read_token(fp_ingress_status);
        if (token != "[[[runtime]]]") begin
            $display("ERROR: token %s != [[[runtime]]]", token);
            $finish;
        end
        token = read_token(fp); // read 1st "[[transaction]]"
        token_ingress_status = read_token(fp_ingress_status);
        forever begin
            @ (negedge clk);
            if (ready == 1) begin
                if (token != "[[[/runtime]]]") begin
                    if (token != "[[transaction]]") begin
                        $display("ERROR: token %s != [[[transaction]]]", token);
                        $finish;
                    end
                    token = read_token(fp); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // load ingress status at beginning of transaction
                    fifo_FFTIN_TDATA.clear();
                    token = read_token(fp);
                    ret = $sscanf(token_ingress_status, "%d", ingress_status);
                    token_ingress_status = read_token(fp_ingress_status);
                    while (token != "[[/transaction]]") begin
                        if (fifo_FFTIN_TDATA.full) begin
                            $display("ERROR: FIFO is full");
                            $finish;
                        end
                        ret = $sscanf(rm_0x(token), "%x", data_integer);
                        data = data_integer;
                        fifo_FFTIN_TDATA.push(data);
                        token = read_token(fp);
                        ret = $sscanf(token_ingress_status, "%d", ingress_status);
                        token_ingress_status = read_token(fp_ingress_status);
                    end
                    FFTIN_TDATA_valid = (ingress_status > 0);
                    token = read_token(fp);
                    token_ingress_status = read_token(fp_ingress_status);
                    fifo_FFTIN_TDATA.snapshot();
                end else begin
                    fifo_FFTIN_TDATA.restore();
                    if (fp != 0) begin
                        $fclose(fp);
                        fp = 0;
                    end
                    if (fp_ingress_status != 0) begin
                        $fclose(fp_ingress_status);
                        fp_ingress_status = 0;
                    end
                end
                transaction_load_FFTIN_TDATA = transaction_load_FFTIN_TDATA + 1;
            end
        end
    end
    
    reg [31:0] transaction_load_FFTIN_TLAST;
    
    initial begin : AXI_stream_driver_FFTIN_TLAST
        integer fp;
        reg [151:0] token;
        reg [1 - 1:0] data;
        reg [151:0] data_integer;
        integer fp_ingress_status;
        reg [151:0] token_ingress_status;
        reg [31:0] ingress_status;
        reg [8 * 5:1] str;
        integer ret;
        
        transaction_load_FFTIN_TLAST = 0;
        fifo_FFTIN_TLAST.clear();
        wait (reset === 1);
        fp = $fopen(`TV_IN_FFTIN_TLAST, "r");
        if (fp == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `TV_IN_FFTIN_TLAST);
            $finish;
        end
        fp_ingress_status = $fopen(`INGRESS_STATUS_FFTIN_TLAST, "r");
        if (fp_ingress_status == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `INGRESS_STATUS_FFTIN_TLAST);
            $finish;
        end
        token = read_token(fp);
        token_ingress_status = read_token(fp_ingress_status);
        if (token != "[[[runtime]]]") begin
            $display("ERROR: token %s != [[[runtime]]]", token);
            $finish;
        end
        token = read_token(fp); // read 1st "[[transaction]]"
        token_ingress_status = read_token(fp_ingress_status);
        forever begin
            @ (negedge clk);
            if (ready == 1) begin
                if (token != "[[[/runtime]]]") begin
                    if (token != "[[transaction]]") begin
                        $display("ERROR: token %s != [[[transaction]]]", token);
                        $finish;
                    end
                    token = read_token(fp); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // load ingress status at beginning of transaction
                    fifo_FFTIN_TLAST.clear();
                    token = read_token(fp);
                    ret = $sscanf(token_ingress_status, "%d", ingress_status);
                    token_ingress_status = read_token(fp_ingress_status);
                    while (token != "[[/transaction]]") begin
                        if (fifo_FFTIN_TLAST.full) begin
                            $display("ERROR: FIFO is full");
                            $finish;
                        end
                        ret = $sscanf(rm_0x(token), "%x", data_integer);
                        data = data_integer;
                        fifo_FFTIN_TLAST.push(data);
                        token = read_token(fp);
                        ret = $sscanf(token_ingress_status, "%d", ingress_status);
                        token_ingress_status = read_token(fp_ingress_status);
                    end
                    FFTIN_TLAST_valid = (ingress_status > 0);
                    token = read_token(fp);
                    token_ingress_status = read_token(fp_ingress_status);
                    fifo_FFTIN_TLAST.snapshot();
                end else begin
                    fifo_FFTIN_TLAST.restore();
                    if (fp != 0) begin
                        $fclose(fp);
                        fp = 0;
                    end
                    if (fp_ingress_status != 0) begin
                        $fclose(fp_ingress_status);
                        fp_ingress_status = 0;
                    end
                end
                transaction_load_FFTIN_TLAST = transaction_load_FFTIN_TLAST + 1;
            end
        end
    end
    
    reg [31:0] transaction_load_FFTIN_TKEEP;
    
    initial begin : AXI_stream_driver_FFTIN_TKEEP
        integer fp;
        reg [151:0] token;
        reg [8 - 1:0] data;
        reg [151:0] data_integer;
        integer fp_ingress_status;
        reg [151:0] token_ingress_status;
        reg [31:0] ingress_status;
        reg [8 * 5:1] str;
        integer ret;
        
        transaction_load_FFTIN_TKEEP = 0;
        fifo_FFTIN_TKEEP.clear();
        wait (reset === 1);
        fp = $fopen(`TV_IN_FFTIN_TKEEP, "r");
        if (fp == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `TV_IN_FFTIN_TKEEP);
            $finish;
        end
        fp_ingress_status = $fopen(`INGRESS_STATUS_FFTIN_TKEEP, "r");
        if (fp_ingress_status == 0) begin // Failed to open file
            $display("ERROR: Failed to open file \"%s\"!", `INGRESS_STATUS_FFTIN_TKEEP);
            $finish;
        end
        token = read_token(fp);
        token_ingress_status = read_token(fp_ingress_status);
        if (token != "[[[runtime]]]") begin
            $display("ERROR: token %s != [[[runtime]]]", token);
            $finish;
        end
        token = read_token(fp); // read 1st "[[transaction]]"
        token_ingress_status = read_token(fp_ingress_status);
        forever begin
            @ (negedge clk);
            if (ready == 1) begin
                if (token != "[[[/runtime]]]") begin
                    if (token != "[[transaction]]") begin
                        $display("ERROR: token %s != [[[transaction]]]", token);
                        $finish;
                    end
                    token = read_token(fp); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // skip transaction number
                    token_ingress_status = read_token(fp_ingress_status); // load ingress status at beginning of transaction
                    fifo_FFTIN_TKEEP.clear();
                    token = read_token(fp);
                    ret = $sscanf(token_ingress_status, "%d", ingress_status);
                    token_ingress_status = read_token(fp_ingress_status);
                    while (token != "[[/transaction]]") begin
                        if (fifo_FFTIN_TKEEP.full) begin
                            $display("ERROR: FIFO is full");
                            $finish;
                        end
                        ret = $sscanf(rm_0x(token), "%x", data_integer);
                        data = data_integer;
                        fifo_FFTIN_TKEEP.push(data);
                        token = read_token(fp);
                        ret = $sscanf(token_ingress_status, "%d", ingress_status);
                        token_ingress_status = read_token(fp_ingress_status);
                    end
                    FFTIN_TKEEP_valid = (ingress_status > 0);
                    token = read_token(fp);
                    token_ingress_status = read_token(fp_ingress_status);
                    fifo_FFTIN_TKEEP.snapshot();
                end else begin
                    fifo_FFTIN_TKEEP.restore();
                    if (fp != 0) begin
                        $fclose(fp);
                        fp = 0;
                    end
                    if (fp_ingress_status != 0) begin
                        $fclose(fp_ingress_status);
                        fp_ingress_status = 0;
                    end
                end
                transaction_load_FFTIN_TKEEP = transaction_load_FFTIN_TKEEP + 1;
            end
        end
    end

endmodule
