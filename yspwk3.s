	.file	"yspwk3.c"
	.text
	.globl	CLOCK
	.type	CLOCK, @function
CLOCK:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	clock_gettime
	movq	-16(%rbp), %rax
	imulq	$1000, %rax, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-8(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC0(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	CLOCK, .-CLOCK
	.section	.rodata
	.align 8
.LC3:
	.string	"Time for the %d loop = %4.2f milliseconds\n"
.LC4:
	.string	"Element %d,%d = %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$3145840, %rsp
	movl	%edi, -3145812(%rbp)
	movq	%rsi, -3145824(%rbp)
	movl	$145, %edi
	call	srand
	movl	$0, -4(%rbp)
	jmp	.L4
.L7:
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	call	rand
	cvtsi2ss	%eax, %xmm0
	movss	.LC1(%rip), %xmm1
	divss	%xmm1, %xmm0
	movl	-8(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	%xmm0, -1048656(%rbp,%rax,4)
	addl	$1, -8(%rbp)
.L5:
	cmpl	$511, -8(%rbp)
	jle	.L6
	addl	$1, -4(%rbp)
.L4:
	cmpl	$511, -4(%rbp)
	jle	.L7
	movl	$0, -4(%rbp)
	jmp	.L8
.L11:
	movl	$0, -8(%rbp)
	jmp	.L9
.L10:
	call	rand
	cvtsi2ss	%eax, %xmm0
	movss	.LC1(%rip), %xmm1
	divss	%xmm1, %xmm0
	movl	-8(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	%xmm0, -2097232(%rbp,%rax,4)
	addl	$1, -8(%rbp)
.L9:
	cmpl	$511, -8(%rbp)
	jle	.L10
	addl	$1, -4(%rbp)
.L8:
	cmpl	$511, -4(%rbp)
	jle	.L11
	movl	$0, -4(%rbp)
	jmp	.L12
.L15:
	movl	$0, -8(%rbp)
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rax, %rdx
	movl	.LC2(%rip), %eax
	movl	%eax, -3145808(%rbp,%rdx,4)
	addl	$1, -8(%rbp)
.L13:
	cmpl	$511, -8(%rbp)
	jle	.L14
	addl	$1, -4(%rbp)
.L12:
	cmpl	$511, -4(%rbp)
	jle	.L15
	movl	$16, -36(%rbp)
	movl	$0, %eax
	call	CLOCK
	movsd	%xmm0, -3145832(%rbp)
	movq	-3145832(%rbp), %rax
	movq	%rax, -48(%rbp)
	movl	$512, %eax
	cltd
	idivl	-36(%rbp)
	imull	-36(%rbp), %eax
	movl	%eax, -52(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L16
.L25:
	movl	$0, -16(%rbp)
	jmp	.L17
.L24:
	movl	$0, -4(%rbp)
	jmp	.L18
.L23:
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L19
.L22:
	movl	-8(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	-3145808(%rbp,%rax,4), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm2
	movsd	%xmm2, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L20
.L21:
	movl	-12(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	-1048656(%rbp,%rax,4), %xmm1
	movl	-8(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	-2097232(%rbp,%rax,4), %xmm0
	mulss	%xmm1, %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movsd	-32(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	addl	$1, -12(%rbp)
.L20:
	movl	-36(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	cmpl	-12(%rbp), %eax
	jg	.L21
	movsd	-32(%rbp), %xmm0
	cvtpd2ps	%xmm0, %xmm0
	movl	-8(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	movss	%xmm0, -3145808(%rbp,%rax,4)
	addl	$1, -8(%rbp)
.L19:
	movl	-36(%rbp), %eax
	movl	-16(%rbp), %edx
	addl	%edx, %eax
	cmpl	-8(%rbp), %eax
	jg	.L22
	addl	$1, -4(%rbp)
.L18:
	cmpl	$511, -4(%rbp)
	jle	.L23
	movl	-36(%rbp), %eax
	addl	%eax, -16(%rbp)
.L17:
	movl	-16(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L24
	movl	-36(%rbp), %eax
	addl	%eax, -20(%rbp)
.L16:
	movl	-20(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L25
	movl	$0, %eax
	call	CLOCK
	movsd	%xmm0, -3145832(%rbp)
	movq	-3145832(%rbp), %rax
	movq	%rax, -64(%rbp)
	movsd	-64(%rbp), %xmm0
	subsd	-48(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	-36(%rbp), %edx
	movq	%rax, -3145832(%rbp)
	movsd	-3145832(%rbp), %xmm0
	movl	%edx, %esi
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	movss	-3145808(%rbp), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$0, %edx
	movl	$0, %esi
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movss	-3016532(%rbp), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$63, %edx
	movl	$63, %esi
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movss	-2097236(%rbp), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$511, %edx
	movl	$511, %esi
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	2696277389
	.long	1051772663
	.align 4
.LC1:
	.long	1325400064
	.align 4
.LC2:
	.long	0
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
