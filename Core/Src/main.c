#include "main.h"
#include "stm32f4xx_it.h"   // <-- gives visibility to tick_ms

void delay_ms(uint32_t ms)
{
    uint32_t start = tick_ms;
    while ((tick_ms - start) < ms);
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    SysTick_Config(SystemCoreClock / 1000);

    while (1)
    {
        GPIOA->ODR ^= (1U << 5);
        delay_ms(500);
    }
}
