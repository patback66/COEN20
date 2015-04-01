		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; int32_t iexp(int32_t x, uint32_t n)
; ------------------------------------------------------------------------------------------

		EXPORT  iexp
iexp

	; The first parameter (x) is passed to this function in R0.
	; The second parameter (n) is passed to this function in R1.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here ...

		BX	LR		; return

		END
