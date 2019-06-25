/* header file */
#include "inttypes.h"

/* register base addresses */
#define RCC_AHB1ENR 0x40023830
#define GPIOB_BASE 0x40020400
#define GPIOC_BASE 0x40020800

/* All register or bits offset */
#define MODER 0
#define IDR 4
#define ODR 5
#define BSRR 6
#define Px0 0
#define Px1 1
#define Px2 2
#define Px3 3

/* useful logic */
#define GPIOBEN 1 << 1
#define GPIOCEN 1 << 2
#define SET 1
#define OUTPUT 1
#define RS_SET 1 << 0
#define RS_CLR 1 << (0 + 16)
#define RW_CLR 1 << (1 + 16)
#define E_SET 1 << 2
#define E_CLR 1 << (2 + 16)

/* public method prototypes */
void lcd_init();
void lcd_clear();
void lcd_home();
void lcd_set_position(uint8_t, uint8_t);
int lcd_print_string(char[]);
void lcd_print_num(int);
