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
        LDR R2,=0       ; i
        LDR R3,=1       ; result
LOOP:                   ; for(i=0;i<n;i++)
        CMP R2,R1       ; if(i<n)
        BGE DONE
        MULS R3,R3,R0   ; result*=x
        ADD R2,R2,#1    ; i++
        B LOOP
DONE:
        MOV R0,R3
        BX LR		; return

        END
