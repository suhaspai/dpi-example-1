module top;

   import "DPI-C" function int dpi_input
     (
      input byte         c,
      input shortint     h,
      input int          i,
      input longint      l,
      input real         d,
      input string       s,
      input bit          sv_bit,
      input bit [9:0]    sv_bit_vec,
      input logic        sv_logic,
      input reg          sv_reg,
      input logic [11:0] sv_logic_vec,
      input logic [13:0] sv_reg_vec,
      ) ;

   import "DPI-C" function void dpi_output 
     (
      output logic [11:0] sv_logic_vec,
      int                 i
      );

   byte                   b = 8'h31;       // ascii '1'
   shortint               h = 16'haabb;
   int                    i = 32'haabbccdd;
   longint                l = 64'h8899aabb_ccddeeff;
   real                   r = 3.1415987; 
   string                 s = "This is a DPI mapping example!";

   bit                    sv_bit = 1'b0;
   bit [9:0]              sv_bit_vec = 10'b1010101010;
   logic                  sv_logic   = 1'b1;
   reg                    sv_reg     = 1'b0;
   logic [11:0]           sv_logic_vec  = 12'b010101010101;
   reg [13:0]             sv_reg_vec    = 14'b10101010101010;

   logic [11:0]           sv_logic_vec_out;
   int                    i_out;
   int                    ret;

   initial begin

      ret = dpi_input(b, h, i, l, r, s, sv_bit, sv_bit_vec, sv_logic, sv_reg, sv_logic_vec, sv_reg_vec);

      dpi_output(sv_logic_vec_out, i_out);

      $display("Hello from SystemVerilog!");
      $display("sv_logic_vec_out=%x  i_out=%x", sv_logic_vec_out, i_out);
      
      $finish(0);

   end
   
endmodule

