		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; uint32_t isqrt(uint32_t x)
; ------------------------------------------------------------------------------------------

		EXPORT  isqrt
isqrt

	; The one parameter (x) is passed to this function in R0.
	; The function should return the result in R0

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here....

		BX	LR	; return

        	END
