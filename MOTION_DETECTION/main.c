#include "stm32f401rbt6.h"
#include "systick_delay.h"
unsigned int pir_sensor = 0;



void ADC_IRQHandler(void)
{
	//	unsigned int potentiometer = 0;

    pir_sensor = ADC_DR;  // Read the ADC conversion result (Data Register)
    ADC_SR &= ~(0x1 << 1);   // Clear EOC (End of Conversion) flag in ADC_SR

   if (pir_sensor > 1500)
    {
        GPIOB_ODR ^= (0x1 << 13);  // Toggle PB13 (LED ON)
		//	KM_mdelay(5000); 
		//	GPIOB_ODR |=(0X01<<13);	//OFF RED LED
			
    }
}

int main()
{


    // Enable clock for GPIOC (Port C) and GPIOB (Port B)
    RCC_AHB1ENR |= (0x1 << 2);  // Enable GPIOC clock
    RCC_AHB1ENR |= (0x1 << 1);  // Enable GPIOB clock

    // GPIOC configuration: Set PC1 as Analog Input (for potentiometer)
    GPIOC_MODER &= ~(0x3 << 2);
    GPIOC_MODER |= (0x3 << 2);  

    // GPIOB configuration: Set PB13 as Output (for LED)
    GPIOB_MODER &= ~(0x3 << 26);
    GPIOB_MODER |= (0x1 << 26);  

    // Enable clock for ADC1
    RCC_APB2ENR |= (0x1 << 8);  

    // ADC Configuration
    ADC_CR1 |= (0x1 << 8);     // Enable Scan Mode (if multiple channels are used)
    ADC_SQR3 |= 0x0000000B;    // Select channel 11 (PC1)
    ADC_CR2 |= (0x1 << 10);    // Enable EOCS (End of Conversion Selection)
    ADC_CR1 |= (0x1 << 5);     // Enable ADC EOC interrupt

    // Continuous Conversion Mode
    ADC_CR2 |= (0x1 << 1);  

    // Data Alignment and ADC Clock Settings
    ADC_CR2 &= ~(0x1 << 29);  // Right alignment
    ADC_CR2 |= (0x1 << 28);   // 12-bit resolution
    ADC_CR2 |= 0x0F000000;    // ADC Clock configuration

    // Enable ADC interrupt in NVIC
    NVIC_ISER0 |= (0x1 << 18);  

    // Enable ADC
    ADC_CR2 |= (0x1 << 0);  

    // Start ADC conversion
    ADC_CR2 |= (0x1 << 30);  


while(1)
{
    
    ;
 
	} 
}
