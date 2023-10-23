`timescale 1ns / 1ps
module fft_tb(
    );
    
    reg aclk;
    reg aresetn;
   
    reg [31:0] in_data;
    reg in_valid;
    reg in_last;
    wire in_ready;
   
    reg [7:0] config_data;
    reg config_valid;
    wire config_ready;
   
    wire [31:0] out_data;
    wire out_valid;
    wire out_last;
    reg out_ready;
   
    reg [31:0] input_data[15:0];
   
    integer i;
   
    fft_top fft16(
        .aclk(aclk),
        .areset(aresetn),
       
        .data_in(in_data),
        .valid_in(in_valid),
        .ready_in(in_ready),
        .last_in(in_last),
       
        .config_data(config_data),
        .config_valid(config_valid),
        .config_ready(config_ready),
       
        .data_out(out_data),
        .valid_out(out_valid),
        .last_out(out_last),
        .ready_out(out_ready)
    );
   
    always #5 aclk=~aclk;
   
    initial begin
        aclk=0;
        aresetn=0;
       
        in_valid=0;
        in_data=32'd0;
        in_last=0;
       
        out_ready=1;
       
        config_data=8'd0;
        config_valid=0;
       
        for(i=0;i<=15;i=i+1)
            input_data[i]=32'd0;
    end  
   
    initial begin
        #70
        aresetn=1;
        input_data[0]=32'h40151EB0;
        input_data[1]=32'h3FC00000;
        input_data[2]=32'h4023D70A;
        input_data[3]=32'hBDE147AE;
        input_data[4]=32'hC08C28F6;
        input_data[5]=32'h3F83D70A;
        input_data[6]=32'h3FE28F5C;
        input_data[7]=32'h3F0A3D71;
        input_data[8]=32'hC050A3D7;
        input_data[9]=32'hBF0A3D71;
        input_data[10]=32'h3F8147AE;
        input_data[11]=32'h40070A3D;
        input_data[12]=32'h403851EC;            
        input_data[13]=32'h4047AE14;
        input_data[14]=32'hBE6B851F;
        input_data[15]=32'hC0151EB8;
    end
   
    initial begin
        #100 config_data=1;
        #5 config_valid=1;
       
        while(config_ready==0)
            config_valid=1;
           
        #5 config_valid=0;
    end
   
    initial begin
        #100 for(i=15;i>=0;i=i-1) begin
            #10 if(i==0)
                in_last=1;
               
            in_data=input_data[i];
            in_valid=1;
           
            while(in_ready==0)
                in_valid=1;
        end
        #10 in_valid=0;
        in_last=0;
    end
   
    initial begin
        #100 wait(out_valid==1);
        #300 out_ready=0;
    end
endmodule
