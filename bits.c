/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void){
  //An 8 bit mask that contains only even bits     
  int test8 = 0x55;
  //pads eight 0s on the end
  int test16 = test8<<8;
  //16 bit mask that contains only even bits
  int test16fix = test16+test8;
  //pads sixteen 0s on the end
  int test32 = test16fix<<16;
  //32 bit mask that contains only even bits
  int test32fix = test32+test16fix;
  return test32fix;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int sum = x+y;
  //A mask that holds -1
  int neg = ~1+1;
  //checks if x is negative
  int x_check = x>>31&neg;
  //checks if y is negative
  int y_check =	y>>31&neg;
  //checks if the sum is negative
  int sum_check = sum>>31&neg;
  //if x<0 && y<0 && sum>=0 then negative overflow
  int neg_over = (x_check & y_check) & !sum_check;
  //if x>=0 && y>=0 && sum<0 then negative overflow
  int pos_over = (!x_check & !y_check) & sum_check;
  //if there is either a negative or positive overflow then addOK fails
  return !(neg_over|pos_over);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //makes x into 0
  int zero_check = ((~(!!x)) << 31) >> 31;
  //makes x into 1
  int one_check = (~(!x) << 31) >> 31;
  //checks if x is 0 return z else return y
  return (y & one_check) | (z & zero_check);
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  //checks what the sign of x is
  int mask = x>>31;
  //0000 will & with -x which only leaves postive x to be returned
  return (x&~mask)|((~x+1)&mask);
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  //cuts x in half and compares it with itself
  //if odd then there will be an odd amount of 1s leftover
  int check = (x>>16)^x;
  check = (check>>8)^check;
  check = (check>>4)^check;
  check = (check>>2)^check;
  check = (check>>1)^check;
  //checks to see if there is a 1 left or not
  return check&1;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  //largest int = 32767
  //smallest int = -32768
  //moves the lower 16 bit to the left
  int l_shift = x<<16;
  //moves the lower 16 bit back and pad the front of it with its sign
  int r_shift = l_shift>>16;
  //compares x with the sign
  int check = r_shift^x;
  //if there are any 1s in the beginning then it does not fit so logical not
  return  !check;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  //moves the least significant bit to the front and then copy
  //the sign of it all the way back
  return (x<<31)>>31;
}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  //An 8 bit mask containing only the odd bits
  int test8 = 0xAA;
  //Pads eight 0s
  int test16 = test8<<8;
  //A 16 bit mask containing only the odd bits
  int test16fix = test16+test8;
  //Pads 16 0s
  int test32 = test16fix<<16;
  //A 32 bit mask containing only the odd bits
  int test32fix = test32+test16fix;
  return test32fix;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //A mask that is either padded with 0s or 1s depending on the sign of x
  int x_sign = x>>31;
  //A mask that is either padded with 0s or 1s depending on the sign of y
  int y_sign = y>>31;
  //checks sign of the output
  int sign_check = x_sign & !y_sign;
  //checks if either case is negative
  int neg_check = !(x_sign ^ y_sign);
  //checks the sign of the sum
  int sum_sign = (x+~y)>>31;
  //checks if the sum is negative
  int sum_check = neg_check & sum_sign;
  //checks if either of the cases was incorrect
  int case_check = sign_check | sum_check;
  return !case_check;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //Max range
  int top = 0x39;
  //Min range
  int bottom = 0x30;
  //x is greater than the minimum
  int x_minus_bottom = x+(~bottom+1);\
  //x is less than the maximum
  int top_minus_x = top+(~x+1);
  //Fill the bits with the sign of x
  int bottom_shift = x_minus_bottom>>31;
  //Fill the bits with the sign of x
  int top_shift = top_minus_x>>31;
  //If either x<min or x>max than it will fail
  int check = (top_shift|bottom_shift);
  return check+1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  //x*-1
  int opp = ~x+1;
  //returns the lowest bit with a 1
  return x&opp;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  //maask with the first bit negative
  int neg = 1<<31;
  //cut in half and compare the halves with itself
  int x_shift = (x>>1)|x;
  x_shift = (x_shift>>2)|x_shift;
  x_shift = (x_shift>>4)|x_shift;
  x_shift = (x_shift>>8)|x_shift;
  x_shift = (x_shift>>16)|x_shift;
  //checks if the sign was negative and then compare it with itself
  return (((~x_shift>>1)^neg)&x_shift);
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  //1 followed by thirty-one 0s
  int neg = 1<<31;
  //forces a negative value
  int b = uf|neg;
  //mask of something that is not a number
  int NAN = (1<<31)>>9;
  //checks to see if it is in range
  if((NAN&b)==NAN){
    //returns if it is not in range, therefore not a number
    return uf;
  }
  //returns if it is a number
  return b^neg;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  //isolate sign and checks if it is negative
  unsigned s = (uf>>31)&1;
  //isolate exponent
  int exp = (uf>>23)&0xFF;
  //isolate mantissa
  int man = (uf&0x7FFFFF);
  //subtract the exponent by the bias
  int expMask = exp - 127;
  //NAN
  //Infinity or 32 exponents therefore out of range
  if(exp==0xFF||(expMask>0x20)){
    return 0x80000000u;
  }
  //exponent is less than the bias
  //therefore negative power
  if(expMask<0){
    return 0;
  }
  //exponent is 0
  if(expMask == 0){
    //sign is negative
    if(s==1){
      return -1;
    }
    return 1;
    }
  //1^x
  if(man==0 && expMask>0){
    //sign is negative
    if(s==1){
      return -1;
    }
    return 1;
  }
  //no bits
  if(expMask == 0 && man == 0){
    return 0;
  }
  //checks when the sign is negative
  if (s==1){
    //converts back into base10 integer
    //need the negative because sign was negative
    return ~(man<<expMask)+1;
  }
  //converts back into base10 integer
  return man<<expMask;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  //checks sign
  unsigned s = (uf>>31)<<31;
  //isolate exponent and checks how many of the bits are 1s
  unsigned exp = (uf>>23)&0xFF;
  //isolates mantissa and checks how many of the bits are 1s
  unsigned man = uf&0x7FFFFF;
  //NAN
  if(exp==0xFF){
    //if exponent was all 1s, then return the input
    return uf;
  }
  //regular case
  else if(exp>1){
    //lower the exponent by 1 aka divides by 2
    exp = exp - 1;
    //returns the bits in our sign, exponent and mantissa
    return s|(exp<<23)|man;
  }
  //if exp is 1 or 0
  //we are not required to check for the case of it being 0
  else{
    //if exp is 1
    if(exp==1){
      //puts the one back in front of the decimal (normalizes)
      man = man|1<<23;
    }
    //checks if the the fraction needs to be rounded
    if((3&man)==3){
      //rounds our fraction
      man++;
    }
    //divides it by 2
    man = (man >> 1);
    //returns the bits in our sign and mantissa
    return s|man;
  }
}
