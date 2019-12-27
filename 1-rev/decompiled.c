
void _FINI_1(void)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  local_14 = 0;
  while (local_14 < 0x24) {
    s_junior-totally_the_flag_or_maybe_00301020[(long)local_14] =
         s_junior-totally_the_flag_or_maybe_00301020[(long)local_14] ^ s__00301060[(long)local_14];
    local_14 = local_14 + 1;
  }
  bVar1 = true;
  local_c = 0;
  while (local_c < 0x24) {
    if (s_junior-totally_the_flag_or_maybe_00301020[(long)local_c] !=
        (&DAT_003010a0)[(long)(local_c * 2 + 1)]) {
      bVar1 = false;
    }
    local_c = local_c + 1;
  }
  sleep(10);
  puts("aber es ist nur noch eine sache von sekunden!");
  if (bVar1) {
    puts("correct!");
  }
  return;
}
