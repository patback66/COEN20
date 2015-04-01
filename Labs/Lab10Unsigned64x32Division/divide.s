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



		BX	LR			; Return to calling program.

       		END
