#include <stdio.h>
#include <elf.h>

main(int argc, char* argv[], char* envp[])
{
        Elf32_auxv_t *auxv;
        while(*envp++ != NULL); /*from stack diagram above: *envp = NULL marks end of envp*/

        for (auxv = (Elf32_auxv_t *)envp; auxv->a_type != AT_NULL; auxv++)
      /* auxv->a_type = AT_NULL marks the end of auxv */
        {
                if( auxv->a_type == AT_SYSINFO)
                        printf("AT_SYSINFO is: 0x%x\n", auxv->a_un.a_val);
        }
}

