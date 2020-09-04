#include<avr/io.h>       // Header file for basic avr input/output
#include<util/delay.h>   // header file for delay generation
#include<avr/wdt.h>
#include <avr/sleep.h>

register unsigned int flashTimer asm("r26");


long readVcc() {
  // Read 1.1V reference against AVcc
  // set the reference to Vcc and the measurement to the internal 1.1V reference
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2);
 _delay_us(20000); // Wait for Vref to settle
  
  ADCSRA |= _BV(ADSC); // Start conversion
 
  while (bit_is_set(ADCSRA,ADSC)); // measuring

  uint16_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint16_t high = ADCH; // unlocks both

  long result = (high<<8) | low;

  result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
  return result; // Vcc in millivolts*/
}

int main(){
	MCUSR = 0;                       // reset status register flags
    //CLKPR = 0x83; // PRescaler change enable
    //CLKPR = 0x0 ;  // presc 1
		 

    PORTB = 0b00000; 
    DDRB = 0b11000; //SET PB0 and PB1 as output
	wdt_disable();
	
    
	if(flashTimer>25) {
		flashTimer=0;
		int temp = flashTimer;
		//if(readVcc()<100) {
			PORTB |= 0b1000;
		//}
		flashTimer = temp;
	}

	flashTimer++;
	while(1) {
		for(int i=0;i<3;i++) {
			for(int x=0;x<19;x++){  //490us
				PORTB |= 0b10000;
				_delay_us(10);

				PORTB &= 0b01111;
				_delay_us(9);
			}
			if(i<2) {
				_delay_us(8000);
			}
		}
		//_delay_us(150000);
		PORTB = 0b00; 
		wdt_enable(WDTO_120MS);
		wdt_reset();
		set_sleep_mode (SLEEP_MODE_PWR_DOWN);
		sleep_enable();
		sleep_mode();

		while(1);
	}
    return 0;
}