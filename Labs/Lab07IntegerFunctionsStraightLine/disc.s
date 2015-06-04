		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; int32_t disc(int32_t a, int32_t b, int32_t c)
; ------------------------------------------------------------------------------------------

		EXPORT  disc
disc

	; The first parameter (a) is passed to this function in R0.
	; The second parameter (b) is passed to this function in R1.
	; The second parameter (c) is passed to this function in R2.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here ...     
        MUL R1,R1,R1 ;R1 <- b*b
        LDR R3,=4
        MUL R0,R0,R3 ;R0 <- 4*a
        MUL R0,R0,R2 ;R0 <- (4a)*c
        SUB R0,R1,R0 ;R0 <- b^2-4*a*c                
        BX LR        ; return

        END
