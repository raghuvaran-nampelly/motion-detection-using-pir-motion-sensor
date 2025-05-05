/*
*File Name 		:stm32f401rbt6.h
*Description 	:This file contain all Base and Physical Addresess of STM32 Peripherals and Macros.
*/





/***********	ALL BASE ADDRESESS OF STM32F401RBT6******************/
#define RCC_BASEADDR 			(0x40023800)		//RCC_BASEADDRESS

#define GPIOB_BASEADDR 		(0X40020400)		//GPIOB_BASEADDRESS
#define GPIOC_BASEADDR 		(0x40020800)		//GPIOC_BASEADDRESS

#define EXTI_BASEADDR 		(0x40013C00)		//EXTI BASEADDRESESS
#define SYSCFG_BASEADDR 	(0x40013800)			//SYSCONFIG BASEADDRESS
#define ADC_BASEADDR   		(0x40012000)



/*********************ARM CORTEX M4 CORE PHERIPHERIPERALS**********************/
#define NVIC_BASEADDR 		(0xE000E100)		//NVIC BASE ADDRESS


/*******************************************************************************/

//AHB1
#define RCC_AHB1ENR *(int*)(RCC_BASEADDR+0X30)	//RCC_AHB1ENR PHYSICAL ADDRESS
	
//APB2
#define RCC_APB2ENR *(int*)(RCC_BASEADDR+0x44)	//RCC_APB2 PHYSICAL ADDRESS
	


/**************************PHYSICAL ADDRESS*******************************************/

//GPIOB
#define GPIOB_MODER *(int*)(GPIOB_BASEADDR+0x00)	//GPIOB MODER PHYSICAL ADDRESS

#define GPIOB_ODR *(int*)(GPIOB_BASEADDR+0X14)	//GPIOB OUTPUT DATA REGISTER PHYSICAL ADDRESS(GPIOB_ODR)



//GPIOC
#define GPIOC_MODER 						*(int*)(GPIOC_BASEADDR+0X00)			//GPIOC MODER PHYSICAL ADDRESS

#define GPIOC_PUPDR 						*(int*)(GPIOC_BASEADDR+0x0C)			//GPIOC PULLUP PULL DOWN PHYSICAL ADDRESS
	
#define GPIOC_IDR 							*(int*)(GPIOC_BASEADDR+ 0x10)			//GPIOC INPUT DATA REGISTER PHYSICAL ADDRESS



/****************************SYSCONFIG************************************************/

#define SYSCFG_EXTICR3 *(int*)(SYSCFG_BASEADDR+0x10)
#define SYSCFG_EXTICR1 *(int*)(SYSCFG_BASEADDR+0x08)
//EXTI


#define EXTI_FTSR 				*(int*) (EXTI_BASEADDR+0x0C)

#define EXTI_IMR					*(int*) (EXTI_BASEADDR+ 0x00)

#define EXTI_PR 					*(int*) (EXTI_BASEADDR+0x14)
	


#define NVIC_ISER0			  *(int*) (NVIC_BASEADDR+0x04*0)
#define NVIC_ISER1			  *(int*) (NVIC_BASEADDR+0x04*1)
	
#define  STK_CTRL 				*(int*)	  (0xE000E010)
#define  STK_LOAD 				*(int*)  	(0xE000E014)
#define  STK_VAL					*(int*)   (0xE000E018)


//adc register
#define ADC_SQR1					*(int*)		(ADC_BASEADDR+0X2C)
#define ADC_SQR3					*(int*)   (ADC_BASEADDR+0x34)
#define ADC_CR1						*(int*)   (ADC_BASEADDR+0X04)
#define ADC_CR2						*(int*)   (ADC_BASEADDR+0x08)
#define ADC_SR						*(int*)   (ADC_BASEADDR+0x00)
#define ADC_DR						*(int*)		(ADC_BASEADDR+0x4C)

#define ADC_HTR						*(int*)		(ADC_BASEADDR+0x24)	
#define ADC_LTR						*(int*)		(ADC_BASEADDR+0x28)

	