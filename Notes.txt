Address Labels Code Comments
$000 jmp RESET ; Reset Handler
$002 jmp EXT_INT0 ; IRQ0 Handler
$004 jmp EXT_INT1 ; IRQ1 Handler
$006 jmp TIM2_COMP ; Timer2 Compare Handler
$008 jmp TIM2_OVF ; Timer2 Overflow Handler
$00A jmp TIM1_CAPT ; Timer1 Capture Handler
$00C jmp TIM1_COMPA ; Timer1 CompareA Handler
$00E jmp TIM1_COMPB ; Timer1 CompareB Handler
$010 jmp TIM1_OVF ; Timer1 Overflow Handler
$012 jmp TIM0_OVF ; Timer0 Overflow Handler
$014 jmp SPI_STC ; SPI Transfer Complete Handler
$016 jmp USART_RXC ; USART RX Complete Handler
$018 jmp USART_UDRE ; UDR Empty Handler
$01A jmp USART_TXC ; USART TX Complete Handler
$01C jmp ADC ; ADC Conversion Complete Handler
$01E jmp EE_RDY ; EEPROM Ready Handler
$020 jmp ANA_COMP ; Analog Comparator Handler
$022 jmp TWSI ; Two-wire Serial Interface Handler
$024 jmp EXT_INT2 ; IRQ2 Handler
$026 jmp TIM0_COMP ; Timer0 Compare Handler
$028 jmp SPM_RDY ; Store Program Memory Ready Handler
;
$02A RESET: ldi r16,high(RAMEND; Main program start
$02B out SPH,r16 ; Set Stack Pointer to top of RAM
$02C ldi r16,low(RAMEND)
$02D out SPL,r16
$02E sei ; Enable interrupts


Modes of operation:
1. Normal mode
2. Clear Timer on Compare Match (CTC)

TIFR -- Timer interrupt flag register
TCNT0 -- Timer or Counter 0
OCR0  -- Output Compare register
TIMSR: Timer Interrupt Mask Register

OCR0 is compared with the TCTR0 value at all time. If they are the same, while OCIE0 = 1 (set) and Global interrupt = 1. At the next count the Output compare interrupt is 
generated, and the OCF0 is cleared. To manually clear the OCF0, you write 1 to it

Result of the compare is used to generate: Wave or PWM
Compare matches sets the OCF0 (Output Compare Flag 0). This can be used to generate output comapre interrupt request
The counter Top is defined in OCR

Note: All the behaviour of TIMER0 are shown on the OC0 pin

Note: If you initialize the TCNT0 with the same value as OCR0, this is supposed to trigger a match interrupt. However, any CPU write operation to the TCNT0 blocks 
the compare match, thus allowing us to initialize TCNT0 with the same value as OCR0


CS02:0 bit of(TCCR0) // Used to select clock source
WGM01, WGM00 bit of (TCCR0) // Determine the counting direction
 Note: TOV0 is set according to the mode set by WGM1:0. This flag can also be use go generate an interrupt
COM1:0 Define whether the OC0 pin will be cleared/toggled (These bits controls the output of the OC0 pin). The role of these bits are different in each mode of operation
	Note: of COM01:0 = 0, i.e: Don't do anything with the OC0 pin. COM0 (Compare Output Mode). The COM0 decide between inverted and no Inverted PWM


Normal mode:
WGM1:0 = 0. Counting direction = up. No counter clear is performed. The counter overrun after passing it Max 8-bit value (0xFF), then recount from 0x00. When TCNT0
is rest to Zero, the TOV0 is set
