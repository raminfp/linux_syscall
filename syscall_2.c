// syscall tables : https://github.com/torvalds/linux/blob/v3.13/arch/x86/syscalls/syscall_64.tbl#L69
// https://github.com/torvalds/linux/blob/v3.13/arch/x86/kernel/cpu/common.c#L1128
// syscall_init : https://github.com/torvalds/linux/blob/v3.13/arch/x86/include/uapi/asm/msr-index.h#L9
// of syscall table exit syscall number :  60	common	exit			sys_exit
// https://github.com/torvalds/linux/blob/v3.13/arch/x86/kernel/entry_64.S#L629
// gcc -o test syscall_2.c
// ./test
// echo $?

int
main(int argc, char *argv[])
{
  unsigned long syscall_nr = 60;
  long exit_status = 42;

  asm ("movq %0, %%rax\n"
       "movq %1, %%rdi\n"
       "syscall"
    : /* output parameters, we aren't outputting anything, no none */
      /* (none) */
    : /* input parameters mapped to %0 and %1, repsectively */
      "m" (syscall_nr), "m" (exit_status)
    : /* registers that we are "clobbering", unneeded since we are calling exit */
      "rax", "rdi");
}
