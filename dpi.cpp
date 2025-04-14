// C++ Code (dpi.cpp)
// This is the C++ code that will be called from the SystemVerilog module.

#include <iostream>
#include <string.h>

#include "svdpi.h"

svLogicVecVal sv_logic_vec_copy;
int int_copy;

extern "C" int  dpi_input(
   char c,
   short int h,
   int i,
   long int l,
   double d,
   char *s,
   svBit sv_bit,
   svBitVecVal *sv_bit_vec,
   svLogic sv_logic,
   svLogic sv_reg,
   svLogicVecVal* sv_logic_vec,
   svLogicVecVal* sv_reg_vec
)                            
{
   printf("\nHello from C DPI function!\n");
   printf("sizeof(char)          = %d, value = %c\n", (int) sizeof(c), c );
   printf("sizeof(short int)     = %d, value = %hx\n", (int) sizeof(h), h);
   printf("sizeof(int)           = %d, value = %x\n", (int) sizeof(i), i );
   printf("sizeof(long int)      = %d, value = %lx\n", (int) sizeof(l), l);
   
   printf("sizeof(double)        = %d, value = %f\n", (int) sizeof(d), d );
   printf("sizeof(char *)        = %d, value = %s\n", (int) sizeof(s), s);

   
   printf("sizeof(sv_bit)        = %d, value = %x\n", (int) sizeof(sv_bit), sv_bit);
   printf("sizeof(sv_bit_vec)    = %d, value = %x\n", (int) sizeof(sv_bit_vec), *sv_bit_vec );
   printf("sizeof(sv_logic)      = %d, value = %x\n", (int) sizeof(sv_logic), sv_logic );
   printf("sizeof(sv_reg)        = %d, value = %x\n", (int) sizeof(sv_reg), sv_reg );   
   printf("sizeof(sv_logic_vec)  = %d, aval = %x bval = %x\n", (int) sizeof(sv_logic_vec), sv_logic_vec->aval, sv_logic_vec->bval );
   printf("sizeof(sv_reg_vec)    = %d, aval = %x bval = %x\n", (int) sizeof(sv_reg_vec), sv_reg_vec->aval, sv_reg_vec->bval );

   memcpy(&sv_logic_vec_copy, sv_logic_vec, sizeof(svLogicVecVal) );
   printf("sizeof(sv_logic_vec_copy) = %d, aval = %x bval = %x\n", (int) sizeof(sv_logic_vec_copy), sv_logic_vec_copy.aval, sv_logic_vec_copy.bval );
   
   int_copy = i;
   printf("int_copy = %x\n", int_copy);
          
   return (0);
} 

extern "C" void  dpi_output(svLogicVecVal* sv_logic_vec, int *i)
{
   memcpy(sv_logic_vec, &sv_logic_vec_copy, sizeof(svLogicVecVal) );
   *i = int_copy;
}   
