	global prodinterno
	section .text

; *v1 -> RDI
; *v2 -> Rsi
; N   -> RDX
; *ip -> RCX 

prodinterno:
	xorpd	xmm0,	xmm0 ;  limpia registro
	xorpd	xmm1,	xmm1 ;  limpia registro
	xorpd	xmm2,	xmm2 ;  limpia registro
	cmp	rdx,	0
	je	done
next:
	movss	xmm0,	[rdi]
	movss	xmm1,	[rsi]
	mulss	xmm0,	xmm1
	addss	xmm2,	xmm0
	add	rdi,	4
	add	rsi,	4
	sub	rdx,	1
	jnz	next	
done:
	movss	[rcx],	xmm2
	ret