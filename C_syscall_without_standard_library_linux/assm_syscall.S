// Putting it all together, our _start function needs to:
// - zero rbp
// - put argc into rdi (1st parameter for main)
// - put the stack address of argv[0] into rsi (2nd param for main),
//   which will be interpreted as an array of char pointers.
// - align stack to 16-bytes
// - call main

.intel_syntax noprefix
.text
    .globl _start, syscall5

    _start:
	// _start function
	// avoid error :
	/*
	/usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/../../../../
	x86_64-pc-linux-gnu/bin/ld: warning: cannot find entry symbol
	_start; defaulting to 0000000000400120
	*/
        xor rbp,rbp  /* xoring a value with itself = 0 */
        pop rdi      /* rdi = argc */
        	     /* the pop instruction already added 8 to rsp */
        mov rsi,rsp  /* rest of the stack as an array of char ptr */

        	     /* zero the las 4 bits of rsp, aligning it to 16 bytes
           	        same as "and rsp,0xfffffffffffffff0" because negative
           		numbers are represented as
           		max_unsigned_value + 1 - abs(negative_num) */
        and rsp,-16
        call main

	// _EXIT
	// man 2 _EXIT
	// avoid error : Segmentation fault (core dumped)
	mov rdi,rax /* syscall param 1 = rax (ret value of main) */
        mov rax,60 /* SYS_exit */
        syscall
	//
	ret

    syscall5:
        mov rax,rdi
        mov rdi,rsi
        mov rsi,rdx
        mov rdx,rcx
        mov r10,r8
        mov r8,r9
        syscall
        ret
