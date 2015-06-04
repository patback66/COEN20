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
        LDR R1,=0x40000000
        LDR R2,=0
LOOP:   
        CMP R1,#0               ; while(m != 0)
        BEQ DONE
        ORR R3,R2,R1            ; b = y | m
        LSR R2,R2,#1            ; y = y >> 1
        CMP R3,R0               
        ITT LS                  ; if(b <= x)
        SUBLS R0,R0,R3          ; x = x - b
        ORRLS R2,R2,R1          ; y = y | m
        LSR R1,R1,#2            ; m = m >> 2
        B LOOP                  ; loop again
DONE:
        MOV R0,R2               ; R0<-R2
        BX LR	                ; return y
  
        END
