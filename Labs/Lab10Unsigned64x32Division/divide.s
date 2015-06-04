        rseg CODE:CODE(2)
        THUMB

; ------------------------------------------------------------------------------------------
; uint32_t UDivide64x32(uint64_t dividend64, uint32_t divisor32)
; ------------------------------------------------------------------------------------------

		EXPORT  UDivide64x32
UDivide64x32

	; The two parameters are passed to this function as follows:
	;
	; dividend64 is in register pair R1.R0
	; divisor32 is in register R2
	;
	; The quotient must be returned in register R0
        LDR R3,=31              ; R3<-31
Loop:   CMP R3,#0               ; while(R3>=0)
        BLT EndLoop
        LSL R1,R1,#1            ; dividend = dividend << 1;
        ORR R1,R1,R0,LSR #31
        LSL R0,R0,#1
        CMP R1,R2               ; if(R1 >= R2)
        BLT EndIf
        SUB R1,R1,R2            ; R1 = R1-R2
        ADD R0,R0,#1            ; R0 = R0++
EndIf:  SUB R3,R3,#1            ; R3--
        B Loop
EndLoop:
        BX LR			; Return to calling program.
        END
