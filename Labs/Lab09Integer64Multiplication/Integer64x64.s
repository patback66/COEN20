        rseg CODE:CODE(2)
        THUMB
        
; ------------------------------------------------------------------------------------------
; int64_t IntegerProduct64x64(int64_t a, int64_t b)
; ------------------------------------------------------------------------------------------

		EXPORT  IntegerProduct64x64
IntegerProduct64x64

	; The two parameters are passed to this function as follows:
	;
	; a<63..32> is in register R1; a<31..0> is in register R0
	; b<63..32> is in register R3; b<31..0> is in register R2
	;
	; Bits 63..32 of the product must be returned in register R1
	; Bits 31..0 of the product must be returned in register R0
	;
	; The value of all other registers must be preserved!
        PUSH {R4,R5}
        UMULL R4,R5,R0,R2       ;R4Lo, R5Hi, <- Alo*Blo
        MLA R5,R0,R3,R5         ;R5 <- (Alo*Bhi)+R4lo
        MLA R1,R1,R2,R5         ;ProductHi <- (AHi*Blo)+R5
        MOV R0,R4               ;ProductLo <- R4
        POP {R4,R5}
	BX LR		        ; Return to calling program.

        END
