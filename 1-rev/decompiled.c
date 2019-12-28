#include <stdbool.h>
#include <stdio.h>

unsigned char flag[] = "junior-totally_the_flag_or_maybe_00301020";
unsigned char f2[] = "this_should_totally_be_a_hering_on_a_kuchenblech";

unsigned char DAT_003010a0[] = { 00,0x1e,0x00,0x1a,0x00,0x00,0x00,0x36,0x00,0x0a,0x00,0x10,0x00,0x54,0x00,0x00,0x00,0x01,0x00,0x33,0x00,0x17,0x00,0x1c,0x00,0x00,0x00,0x09,0x00,0x14,0x00,0x1e,0x00,0x39,0x00,0x34,0x00,0x2a,0x00,0x05,0x00,0x04,0x00,0x04,0x00,0x09,0x00,0x3d,0x00,0x03,0x00,0x17,0x00,0x3c,0x00,0x05,0x00,0x3e,0x00,0x14,0x00,0x03,0x00,0x03,0x00,0x36,0x00,0x0f,0x00,0x4e,0x00,0x55,0x00};

unsigned char s__00301060[] = {0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x00};


/* unsigned char FUN_001007c0(unsigned char uParm1,long lParm2) */
/* { */
/*   int iVar1; */
/*   byte bVar2; */
/*   uint uVar3; */
/*   int local_10; */
/*    */
/*   local_10 = 0; */
/*   while (local_10 < 0x24) { */
/*     flag[(long)(local_10 + 0x40)] = */
/*          *(char *)((long)local_10 + *(long *)(lParm2 + 8)); */
/*     uVar3 = (uint)((int)flag[(long)local_10] >> 0x1f) >> 0x18 */
/*     ; */
/*     iVar1 = (((int)flag[(long)local_10] + uVar3 & 0xff) - */
/*             uVar3) + 0x100; */
/*     bVar2 = (byte)(iVar1 >> 0x37); */
/*     flag[(long)local_10] = */
/*          ((char)iVar1 + (bVar2 >> 1) & 0x7f) - (bVar2 >> 1); */
/*     flag[(long)local_10] = */
/*          flag[(long)local_10]; */
/*     local_10 = local_10 + 1; */
/*   } */
/*   puts("wrong!"); */
/*   return 0; */
/* } */

void _INIT_1(void)
{
  int local_c;

  local_c = 0;
  while (local_c < 0x24) {
    flag[(long)local_c] =
         flag[(long)(0x23 - local_c)];
    local_c = local_c + 1;
  }
  return;
}

void _FINI_1(void)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  local_14 = 0;
  while (local_14 < 0x24) {
    flag[(long)local_14] =
         flag[(long)local_14] ^ s__00301060[(long)local_14];
    local_14 = local_14 + 1;
  }
  bVar1 = true;
  local_c = 0;
  while (local_c < 0x24) {
    if (flag[(long)local_c] !=
        (DAT_003010a0)[(long)(local_c * 2 + 1)]) {
      bVar1 = false;
    }
    local_c = local_c + 1;
  }
  puts("aber es ist nur noch eine sache von sekunden!");
  if (bVar1) {
    puts("correct!");
  }
  return;
}

int main() {
  bool bVar1;
  int i;
  int local_c;
  
  _INIT_1();
  i = 0;
  while (i < 0x24) {
        printf("%02X ^ %02X", flag[(long)i], s__00301060[(long)i]);
    flag[(long)i] =
         flag[(long)i] ^ s__00301060[(long)i];
        printf(" = %02X\n", flag[(long)i]);
    i = i + 1;
  }
  bVar1 = true;
  int j = 0;
  while (j < 0x24) {
        printf("%02X == %02X\n", flag[(long)j], (DAT_003010a0)[(long)(j * 2 + 1)]);
    if (flag[(long)j] !=
        (DAT_003010a0)[(long)(j * 2 + 1)]) {
      bVar1 = false;
    }
    j = j + 1;
  }
  puts("aber es ist nur noch eine sache von sekunden!");
  if (bVar1) {
    puts("correct!");
  }


  int z = 0;
  while (z < 0x24) {
    //printf("%02X ^ %02X",DAT_003010a0[(long)(z * 2 + 1)],flag[(long)z]);
    unsigned char result = DAT_003010a0[(long)(z * 2 + 1)] ^ flag[(long)z];
    printf("%c", result, result);
    z = z + 1;
  }
  return 0;
}
