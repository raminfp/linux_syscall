// LD_SHOW_AUXV=1 ./test
// gcc -m32 -o test auxilliary_vectors_syscall.c
// ./test
// echo $?
// output : 42

#include <stdlib.h>
#include <elf.h>
#include <stdio.h>

int
main(int argc, char* argv[], char* envp[])
{
  unsigned int syscall_nr = 1;
  int exit_status = 42;
  Elf32_auxv_t *auxv;

  /* auxilliary vectors are located after the end of the environment
   * variables
   *
   * check this helpful diagram: https://static.lwn.net/images/2012/auxvec.png
   */
  while(*envp++ != NULL);

  /* envp is now pointed at the auxilliary vectors, since we've iterated
   * through the environment variables.
   */
  for (auxv = (Elf32_auxv_t *)envp; auxv->a_type != AT_NULL; auxv++)
  {
    if( auxv->a_type == AT_SYSINFO) {
      break;
    }
  }

  /* NOTE: in glibc 2.16 and higher you can replace the above code with
   * a call to getauxval(3):  getauxval(AT_SYSINFO)
   */

  printf("AT_SYSINFO is: 0x%x\n",auxv->a_un.a_val);

  asm(
      "movl %0,  %%eax    \n"
      "movl %1, %%ebx    \n"
      "call *%2          \n"
      : /* output parameters, we aren't outputting anything, no none */
        /* (none) */
      : /* input parameters mapped to %0 and %1, repsectively */
        "m" (syscall_nr), "m" (exit_status), "m" (auxv->a_un.a_val)
      : /* registers that we are "clobbering", unneeded since we are calling exit */
        "eax", "ebx");
}
