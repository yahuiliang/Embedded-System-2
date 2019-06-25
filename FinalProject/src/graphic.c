/*
 * Test.c
 *
 *  Created on: Feb 6, 2017
 *      Author: Yahui Liang
 */

#include "rotary_api.h"
#include "lcd_api.h"
#include "graphic.h"
#include "delay_api.h"
#include <inttypes.h>

static void create_graphics();

int main() {
    init_graphic();
    self_position1();
    delay_ms(1000);
    self_position2();
    delay_ms(1000);
    self_position3();
    delay_ms(1000);
    self_position4();
    while (1);
    return 0;
}

/* all of these will be stored in CGRAM. */
static uint8_t self_upper_half[] = {0b11000, 0b11111, 0b11111, 0b11000, 0b00000, 0b00000, 0b00000, 0b00000}; // store at 0.
static uint8_t self_lower_half[] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b11111, 0b11111, 0b11000}; // store at 1.
static uint8_t enemy_upper_half[] = {0b11110, 0b00001, 0b00001, 0b11110, 0b00000, 0b00000, 0b00000, 0b00000}; // store at 2.
static uint8_t enemy_lower_half[] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11110, 0b00001, 0b00001, 0b11110}; // store at 3.

void init_graphic() {
    lcd_init();
    create_graphics();
    lcd_set_position(0, 0);
    lcd_data(PLAYER_UPPER);
}

void self_position1() {
    lcd_set_position(1, 0);
    lcd_data(' ');
    lcd_set_position(0, 0);
    lcd_data(PLAYER_UPPER);
}

void self_position2() {
    lcd_set_position(1, 0);
    lcd_data(' ');
    lcd_set_position(0, 0);
    lcd_data(PLAYER_LOWER);
}

void self_position3() {
    lcd_set_position(0, 0);
    lcd_data(' ');
    lcd_set_position(1, 0);
    lcd_data(PLAYER_UPPER);
}

void self_position4() {
    lcd_set_position(0, 0);
    lcd_data(' ');
    lcd_set_position(1, 0);
    lcd_data(PLAYER_LOWER);
}

/*********************************************************************/

typedef struct {
    uint8_t current_position;
    uint8_t previous_position;
} enemy;

typedef struct {
    int row;
    int col;
    int hasUpperBullet;
    int hasLowerBullet;
    int hasUpperEnemy;
    int hasUpperPlayer;
    int hasLowerEnemy;
    int hasLowerPlayer;
} Grid;

void printGrid(Grid grid) {
    if (grid.hasLowerBullet && grid.hasUpperBullet) {

    } else if (grid.hasLowerBullet && !grid.hasLowerBullet) {

    } else if (!grid.hasLowerBullet && grid.hasLowerBullet) {

    } else if (grid.hasLowerEnemy && grid.hasUpperEnemy) {

    } else if (grid.hasLowerEnemy && !grid.hasUpperEnemy) {

    } else if (!grid.hasLowerEnemy && grid.hasUpperEnemy) {

    } else if (grid.hasUpperBullet && grid.hasLowerEnemy) {

    } else if () {

    }
}

void clearGrid(Grid grid) {
    lcd_set_position(grid.row, grid.col);
    lcd_data(' ');
}

static int enemy1count = 0;
static int enemy2count = 0;
static int enemy3count = 0;
static int enemy4count = 0;

static enemy enemy1s[7];
static enemy enemy2s[7];
static enemy enemy3s[7];
static enemy_enemy4s[7];

/**
 * Args:
 * position: it means the position from the starting point.
 */
void enemy1_generates(uint8_t position) {
    if (enemy1count == 7) {
        enemy en = {0, 0};
        enemy1s[enemy1count] = en;
        enemy1count++;
    }
}

void enemy2_generates(uint8_t position) {
    if (enemy2count == 7) {
        enemy en = {0, 0};
        enemy1s[enemy2count] = en;
        enemy2count++;
    }
}

void enemy3_generates(uint8_t position) {

}

void enemy4_generates(uint8_t position) {

}

void enemy1_movement(uint8_t speed_ms) {

}

void enemy2_movement() {

}

void enemy3_movement() {

}

void enemy4_movement() {

}

static void create_graphics() {
    lcd_set_cgram_position(0);
    for (int i = 0; i < SIZE; i++) {
        uint8_t self_upper = self_upper_half[i];
        lcd_data(self_upper);
    }
    for (int i = 0; i < SIZE; i++) {
        uint8_t self_lower = self_lower_half[i];
        lcd_data(self_lower);
    }
    for (int i = 0; i < SIZE; i++) {
        uint8_t enemy_upper = enemy_upper_half[i];
        lcd_data(enemy_upper);
    }
    for (int i = 0; i < SIZE; i++) {
        uint8_t enemy_lower = enemy_lower_half[i];
        lcd_data(enemy_lower);
    }
}
