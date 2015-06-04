		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; uint32_t absval(int32_t x)
; ------------------------------------------------------------------------------------------

		EXPORT  absval
absval
        ; Matthew Koken
	; The first parameter (x) is passed to this function in R0.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here ...
        ASR R1,R0,#31 ; R1 <- sign bit of x
        ADD R0,R0,R1  ; R0 <- signext + x
        EOR R0,R0,R1  ; R0 <- returnValue ^ signext
        BX LR         ; return

        END
