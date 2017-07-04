/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l4xx_hal.h"

/* USER CODE BEGIN Includes */
#include "stm32l4xx_nucleo.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
RCC_ClkInitTypeDef RCC_ClkInitStruct;
RCC_OscInitTypeDef RCC_OscInitStruct;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
  char uart2Data[24] = "Connected to UART Two\r\n";
   HAL_UART_Transmit(&huart2, (uint8_t *)&uart2Data,sizeof(uart2Data), 0xFFFF);

 	uint8_t len = 0;
 	char devidString[512] = {0};
 	uint32_t idcode = DBGMCU->IDCODE & 0xFFF;
 	//len += sprintf(devidString, "Device ID: 0x%lX\r\n", idcode);
 	//printf("%s", devidString);
 	switch (idcode)
 	{
	case 0x410: len += sprintf(devidString+len, "stm32f1xx medium-density"); break;
	case 0x411: len += sprintf(devidString+len, "stm32f2xx"); break;
	case 0x412: len += sprintf(devidString+len, "stm32f1xx low-density"); break;
	case 0x413: len += sprintf(devidString+len, "stm32f4xx"); break;
	case 0x414: len += sprintf(devidString+len, "stm32f1xx high-density"); break;
	case 0x415: len += sprintf(devidString+len, "stm32l475xx/476xx/486xx"); break;
	case 0x416: len += sprintf(devidString+len, "stm32l1xx medium-density"); break;
	case 0x417: len += sprintf(devidString+len, "stm32l0xx"); break;
	case 0x418: len += sprintf(devidString+len, "stm32f1xx connectivity line"); break;
	case 0x419: len += sprintf(devidString+len, "stm32f4xx high-density"); break;
	case 0x420: len += sprintf(devidString+len, "stm32f1xx value line"); break;
	case 0x421: len += sprintf(devidString+len, "stm32f446"); break;
	case 0x422: len += sprintf(devidString+len, "stm32f3xx"); break;
	case 0x423: len += sprintf(devidString+len, "stm32f4xx low power"); break;
	case 0x425: len += sprintf(devidString+len, "stm32l0xx cat. 2"); break;
	case 0x427: len += sprintf(devidString+len, "stm32l1xx medium-density/plus"); break;
	case 0x428: len += sprintf(devidString+len, "stm32f1xx value line high-density"); break;
	case 0x429: len += sprintf(devidString+len, "stm32l1xx cat. 2"); break;
	case 0x430: len += sprintf(devidString+len, "stm32f1xx xl-density"); break;
	case 0x431: len += sprintf(devidString+len, "stm32f411re"); break;
	case 0x432: len += sprintf(devidString+len, "stm32f37x"); break;
	case 0x433: len += sprintf(devidString+len, "stm32f4xx de"); break;
	case 0x434: len += sprintf(devidString+len, "stm32f4xx dsi"); break;
	case 0x435: len += sprintf(devidString+len, "stm32l43x"); break;
	case 0x436: len += sprintf(devidString+len, "stm32l1xx high-density"); break;
	case 0x437: len += sprintf(devidString+len, "stm32l152re"); break;
	case 0x438: len += sprintf(devidString+len, "stm32f334"); break;
	case 0x439: len += sprintf(devidString+len, "stm32f3xx small"); break;
	case 0x440: len += sprintf(devidString+len, "stm32f0xx"); break;
	case 0x441: len += sprintf(devidString+len, "stm32f412"); break;
	case 0x442: len += sprintf(devidString+len, "stm32f09x"); break;
	case 0x444: len += sprintf(devidString+len, "stm32f0xx small"); break;
	case 0x445: len += sprintf(devidString+len, "stm32f04x"); break;
	case 0x446: len += sprintf(devidString+len, "stm32f303 high-density"); break;
	case 0x447: len += sprintf(devidString+len, "stm32l0xx cat. 5"); break;
	case 0x448: len += sprintf(devidString+len, "stm32f0xx can"); break;
	case 0x449: len += sprintf(devidString+len, "stm32f7"); break;
	case 0x451: len += sprintf(devidString+len, "stm32f7xx"); break;
	case 0x457: len += sprintf(devidString+len, "stm32l011"); break;
	case 0x458: len += sprintf(devidString+len, "stm32f410"); break;
	case 0x461: len += sprintf(devidString+len, "stm32l496xx/4A6xx"); break;
	case 0x463: len += sprintf(devidString+len, "stm32f413"); break;
	default: len += sprintf(devidString+len, "unknown device\r\n");
 	}

	uint32_t revCode = (DBGMCU->IDCODE & DBGMCU_IDCODE_REV_ID_Msk) >> DBGMCU_IDCODE_REV_ID_Pos;

	if (idcode == 0x415)
	{
		switch (revCode)
		{
		case 0x1000: len += sprintf(devidString+len, "  Revision 1\r\n"); break;
		case 0x1001: len += sprintf(devidString+len, "  Revision 2\r\n"); break;
		case 0x1003: len += sprintf(devidString+len, "  Revision 3\r\n"); break;
		case 0x1007: len += sprintf(devidString+len, "  Revision 4\r\n"); break;
		default: len += sprintf(devidString+len, " Revision %lX\r\n", revCode); break;
		}
	}

	if (idcode == 0x461)
	{
		switch (revCode)
		{
		case 0x1000: len += sprintf(devidString+len, "  Revision A\r\n"); break;
		case 0x1001: len += sprintf(devidString+len, "  Revision B\r\n"); break;
		default: len += sprintf(devidString+len, " Revision %lX\r\n", revCode); break;
		}
	}
 	printf("%s", devidString);
 	//GUI_DispString(devidString);

 	len = 0;
 	uint32_t cpuid = SCB->CPUID;
 	uint32_t var, pat;
 	pat = (cpuid & 0x0000000F);
 	var = (cpuid & 0x00F00000) >> 20;
 	uint32_t mvfr0;
 	char cpuString[24] = {0};

 	//len += sprintf(cpuString, "CPU ID: 0x");
 	//len += sprintf(cpuString+len, "%lX\r\n", cpuid);

 	if ((cpuid & 0xFF000000) == 0x41000000) // ARM
 		{
 			len += sprintf(cpuString+len, "ARM ");
 			switch((cpuid & 0x0000FFF0) >> 4)
 				{
 					case 0xC20 : len += sprintf(cpuString+len, "Cortex M0 r%ldp%ld\r\n", var, pat); break;
 					case 0xC60 : len += sprintf(cpuString+len, "Cortex M0+ r%ldp%ld\r\n", var, pat); break;
 					case 0xC21 : len += sprintf(cpuString+len, "Cortex M1 r%ldp%ld\r\n", var, pat); break;
 					case 0xC23 : len += sprintf(cpuString+len, "Cortex M3 r%ldp%ld\r\n", var, pat); break;
 					case 0xC24 : len += sprintf(cpuString+len, "Cortex M4 r%ldp%ld\r\n", var, pat); break;
 					case 0xC27 : len += sprintf(cpuString+len, "Cortex M7 r%ldp%ld\r\n", var, pat); break;

 					default : len += sprintf(cpuString+len, "Unknown CORE\r\n");
 				}
 		}

     mvfr0 = *(volatile uint32_t *)0xE000EF40;
 	//mvfr0 = SCB->MVFR0;

     if (mvfr0 > 0){
    	 switch(mvfr0)
     	 	 {
     	 	 case 0x10110021 : len += sprintf(cpuString+len, "Single precision FPU\r\n"); break;
     	 	 case 0x10110221 : len += sprintf(cpuString+len, "Double precision FPU\r\n"); break;
     	 	 //default : len += sprintf(cpuString+len, "No FPU\r\n");
     	 	 default: ;
     	 	 }
     	 }
 	printf("%s",cpuString);

	len = 0;
	char memString[512] = {0};
	switch (idcode)
	{
	case 0x415: len += sprintf(memString+len, "%dK Flash, 128K RAM (96K SRAM1, 32K SRAM2)\r\n", *((unsigned short *)FLASHSIZE_BASE)); break;
	default: len += sprintf(memString+len, "unknown device\r\n");
	}
	printf("%s", memString);

	len = 0;
	char pkgString[128] = {0};
	uint32_t pkg = *((uint32_t *)PACKAGE_BASE) & 0x1F;
	switch (pkg)
	{
	case 0x00000000: len += sprintf(pkgString+len, "LQFP64\r\n"); break;
	case 0x00000001: len += sprintf(pkgString+len, "WLCSP64\r\n"); break;
	case 0x00000002: len += sprintf(pkgString+len, "LQFP100\r\n"); break;
	case 0x00000003: len += sprintf(pkgString+len, "BGA132\r\n"); break;
	case 0x00000004: len += sprintf(pkgString+len, "LQFP144, WLCSP81 or WLCSP72\r\n"); break;
	case 0x00000008: len += sprintf(pkgString+len, "UFQFPN32\r\n"); break;
	case 0x0000000A: len += sprintf(pkgString+len, "UFQFPN48\r\n"); break;
	case 0x0000000B: len += sprintf(pkgString+len, "LQFP48\r\n"); break;
	case 0x0000000C: len += sprintf(pkgString+len, "WLCSP49\r\n"); break;
	case 0x0000000D: len += sprintf(pkgString+len, "UFBGA64\r\n"); break;
	case 0x0000000E: len += sprintf(pkgString+len, "UFBGA100\r\n"); break;
	case 0x00000010: len += sprintf(pkgString+len, "UFBGA169\r\n"); break;
	}
	printf("%s", pkgString);


	len = 0;
	char idString[2048] = {0};
	uint32_t word0 = *(uint32_t *)(UID_BASE);
	uint32_t word1 = *(uint32_t *)(UID_BASE + 0x04);
	uint32_t word2 = *(uint32_t *)(UID_BASE + 0x08);
	uint64_t lotNum;
	char lotNumString[32] = {0};
	lotNum = ((uint64_t)word2 << 24 ) | (word1 >> 8);
	len += sprintf(idString, "Device Unique ID: ");
	len += sprintf(idString+len, "%08lX %08lX %08lX\r\n", word0, word1, word2);
	uint32_t x = word0 & 0xFFFF;
	uint32_t y = (word0 & 0xFFFF0000) >> 16;
	uint32_t wafer = word1 & 0xFF;
	sprintf(lotNumString, "%s", (char *)&lotNum);
	len += sprintf(idString+len, "Wafer %ld of Lot %s\r\n", wafer, lotNumString);
	len += sprintf(idString+len, "Location on wafer: X:%ld, Y:%ld\r\n", x,y);
	printf("%s", idString);


	len = 0;
	char myString[512] = {0};
	len += sprintf(myString+len, "HAL Version: ");
	uint32_t halVersion = HAL_GetHalVersion();
	len += sprintf(myString+len, "%d.", (uint8_t)(halVersion >> 24) & 0xff);
	len += sprintf(myString+len, "%d.", (uint8_t)(halVersion >> 16) & 0xff);
	len += sprintf(myString+len, "%d ", (uint8_t)(halVersion >> 8) & 0xff);
	if ((uint8_t)(halVersion >> 0) & 0xff)
	  {
		len += sprintf(myString+len, "rc%d\r\n", (uint8_t)(halVersion >> 0) & 0xff);
	  }
	else
	  {
		len += sprintf(myString+len, "\r\n");
	  }

	len += sprintf(myString+len, "BSP Version: ");
	uint32_t bspVersion = BSP_GetVersion();
	len += sprintf(myString+len, "%d.", (uint8_t)(bspVersion >> 24) & 0xff);
	len += sprintf(myString+len, "%d.", (uint8_t)(bspVersion >> 16) & 0xff);
	len += sprintf(myString+len, "%d ", (uint8_t)(bspVersion >> 8) & 0xff);
	if ((uint8_t)(bspVersion >> 0) & 0xff)
	  {
		len += sprintf(myString+len, "rc%d\r\n", (uint8_t)(bspVersion >> 0) & 0xff);
	  }
	else
	  {
		len += sprintf(myString+len, "\r\n");
	  }
	printf("%s", myString);


 	printf("\r\n");

 	printf("Oscillators and clocks\r\n");
 	printf("----------------------\r\n");
 	printf("            HSE State: ");
 	switch (RCC_OscInitStruct.HSEState)
 	{
 	case RCC_HSE_OFF: printf("Off\r\n"); break;
 	case RCC_HSE_ON:  printf("On\r\n"); break;
 	case RCC_HSE_BYPASS: printf("Bypass\r\n"); break;
 	}


 	printf("            LSE State: ");
 	switch (RCC_OscInitStruct.LSEState)
 	{
 	case RCC_LSE_OFF: printf("Off\r\n"); break;
 	case RCC_LSE_ON:  printf("On\r\n"); break;
 	case RCC_LSE_BYPASS: printf("Bypass\r\n"); break;
 	}


 	printf("            HSI State: ");
 	switch (RCC_OscInitStruct.HSIState)
 	{
 	case RCC_HSI_OFF: printf("Off\r\n"); break;
 	case RCC_HSI_ON:  printf("On\r\n"); break;
 	}

 	printf("            LSI State: ");
 	switch (RCC_OscInitStruct.LSIState)
 	{
 	case RCC_LSI_OFF: printf("Off\r\n"); break;
 	case RCC_LSI_ON:  printf("On\r\n"); break;
 	}


	printf("        SYSCLK Source: ");
	switch (RCC_ClkInitStruct.SYSCLKSource)
	{
		case RCC_SYSCLKSOURCE_MSI : printf("MSI\r\n"); break;
		case RCC_SYSCLKSOURCE_HSI : printf("HSI\r\n"); break;
		case RCC_SYSCLKSOURCE_HSE : printf("HSE\r\n"); break;
		case RCC_SYSCLKSOURCE_PLLCLK : printf("PLLCLK\r\n"); break;
		default : printf("??\r\n");
	}

 	if (RCC_OscInitStruct.PLL.PLLState > 0) {
 	  printf("           PLL Source: ");
 	  switch (RCC_OscInitStruct.PLL.PLLSource)
 		{
 			case RCC_PLLSOURCE_NONE  : printf("No PLL\r\n"); break;
 			case RCC_PLLSOURCE_MSI : printf("MSI\r\n"); break;
 			case RCC_PLLSOURCE_HSI : printf("HSI\r\n"); break;
 			case RCC_PLLSOURCE_HSE : printf("HSE\r\n"); break;
 		}
 	//printf("       PLL Multiplier: %08lX\r\n", RCC_OscInitStruct.PLL.PLLMUL);
 	  printf("                PLL M: /%ld\r\n", RCC_OscInitStruct.PLL.PLLM);
 	  printf("                PLL N: *%ld\r\n", RCC_OscInitStruct.PLL.PLLN);
 	  printf("                PLL P: ");
 	  switch (RCC_OscInitStruct.PLL.PLLP)
 	    {
 	  	  case RCC_PLLP_DIV7 : printf("/7\r\n"); break;
 	  	  case RCC_PLLP_DIV17 : printf("/17\r\n"); break;

 	    }
 	 printf("                PLL Q: ");
 	 switch (RCC_OscInitStruct.PLL.PLLQ)
 	    {
 	  	  case RCC_PLLQ_DIV2 : printf("/2\r\n"); break;
 	  	  case RCC_PLLQ_DIV4 : printf("/4\r\n"); break;
 	  	  case RCC_PLLQ_DIV6 : printf("/6\r\n"); break;
 	  	  case RCC_PLLQ_DIV8 : printf("/8\r\n"); break;
 	    }
 	 printf("                PLL R: ");
 	 switch (RCC_OscInitStruct.PLL.PLLR)
 	    {
 	  	  case RCC_PLLR_DIV2 : printf("/2\r\n"); break;
 	  	  case RCC_PLLR_DIV4 : printf("/4\r\n"); break;
 	  	  case RCC_PLLR_DIV6 : printf("/6\r\n"); break;
 	  	  case RCC_PLLR_DIV8 : printf("/8\r\n"); break;
 	    }
 	}

	uint32_t latency;
	HAL_RCC_GetClockConfig(&RCC_ClkInitStruct, &latency);
	//printf("           Clock Type: %08lX\r\n", RCC_ClkInitStruct.ClockType);
	//printf("\r\n");

	printf("       AHBCLK Divider: ");
	switch (RCC_ClkInitStruct.AHBCLKDivider)
	{
	case RCC_SYSCLK_DIV1 : printf("/1\r\n"); break;
	case RCC_SYSCLK_DIV2 : printf("/2\r\n"); break;
	case RCC_SYSCLK_DIV4 : printf("/4\r\n"); break;
	case RCC_SYSCLK_DIV8 : printf("/8\r\n"); break;
	case RCC_SYSCLK_DIV16 : printf("/16\r\n"); break;
	case RCC_SYSCLK_DIV64 : printf("/64\r\n"); break;
	case RCC_SYSCLK_DIV128 : printf("/128\r\n"); break;
	case RCC_SYSCLK_DIV256 : printf("/256\r\n"); break;
	case RCC_SYSCLK_DIV512 : printf("/512\r\n"); break;
	}

	printf("      APB1CLK Divider: ");
	switch (RCC_ClkInitStruct.APB1CLKDivider)
	{
	case RCC_CFGR_PPRE1_DIV1 : printf("/1\r\n"); break;
	case RCC_CFGR_PPRE1_DIV2 : printf("/2\r\n"); break;
	case RCC_CFGR_PPRE1_DIV4 : printf("/4\r\n"); break;
	case RCC_CFGR_PPRE1_DIV8 : printf("/8\r\n"); break;
	case RCC_CFGR_PPRE1_DIV16 : printf("/16\r\n"); break;
	}


	printf("      APB2CLK Divider: ");
	switch (RCC_ClkInitStruct.APB2CLKDivider)
	{
	case RCC_CFGR_PPRE1_DIV1 : printf("/1\r\n"); break;
	case RCC_CFGR_PPRE1_DIV2 : printf("/2\r\n"); break;
	case RCC_CFGR_PPRE1_DIV4 : printf("/4\r\n"); break;
	case RCC_CFGR_PPRE1_DIV8 : printf("/8\r\n"); break;
	case RCC_CFGR_PPRE1_DIV16 : printf("/16\r\n"); break;
	}

	printf("        Flash latency: %lX\r\n", latency);


 	printf("\r\n");
 	printf("Core registers\r\n");
 	printf("--------------\r\n");
	register int r0 asm ("r0");
	printf("           r0: 0x%08X\r\n", r0);
	register int r1 asm ("r1");
	printf("           r1: 0x%08X\r\n", r1);
	register int r2 asm ("r2");
	printf("           r2: 0x%08X\r\n", r2);
	register int r3 asm ("r3");
	printf("           r3: 0x%08X\r\n", r3);
	register int r4 asm ("r4");
	printf("           r4: 0x%08X\r\n", r4);
	register int r5 asm ("r5");
	printf("           r5: 0x%08X\r\n", r5);
	register int r6 asm ("r6");
	printf("           r6: 0x%08X\r\n", r6);
	register int r7 asm ("r7");
	printf("           r7: 0x%08X\r\n", r7);
	register int r8 asm ("r8");
	printf("           r8: 0x%08X\r\n", r8);
	register int r9 asm ("r9");
	printf("           r9: 0x%08X\r\n", r9);
	register int r10 asm ("r10");
	printf("          r10: 0x%08X\r\n", r10);
	register int r11 asm ("r11");
	printf("          r11: 0x%08X\r\n", r11);
	register int r12 asm ("r12");
	printf("          r12: 0x%08X\r\n", r12);
	register int sp asm ("sp");
	printf("stack pointer: 0x%08X\r\n", sp);
	register int lr asm ("lr");
	printf("link register: 0x%08X\r\n", lr);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  //RCC_OscInitTypeDef RCC_OscInitStruct;
  //RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the main internal regulator output voltage 
    */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART2 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
