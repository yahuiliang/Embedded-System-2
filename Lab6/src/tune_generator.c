/*
 * CE2812 - 021
 * Winter 2016
 * Lab 6 - Play a Tune
 * Name: Yahui Liang
 * Created: 01/21/2017
 */

/* All included header files */
#include "gpio_api.h"
#include "tim2to5_api.h"
#include <inttypes.h>
#include <tim2to5_api.h>
#include "delay_api.h"
#include "tune_generator.h"

/* Private method prototype */
static void tone(uint32_t, uint32_t);

/**
 * Initializes the tune generator. This method mainly configures the timer
 * and the correspond pin.
 */
void init_tune_generator() {
    init_timer3();
    init_gpiox(1); // initialize GPIOB

    set_gpio_pointer(GPIOB_BASE);
    set_to_alt_func_mode(4); // set pin4 to alternate function mode.
    set_alt_function(4, 2);

    set_timer_pointer(TIM3_BASE);
    set_to_output_cmp_mode();
}

/**
 * The method can play a song.
 * Args:
 * song_notes: the array which stores all notes of a song.
 */
void play_song(const note* song_notes) {
    set_timer_pointer(TIM3_BASE);
    int index = 0;
    note a_note = song_notes[index++];
    // iterate through the array and make sound for each note.
    while (a_note.frequency != 0 && a_note.duration != 0) {
        tone(a_note.frequency, a_note.duration);
        delay_ms(a_note.duration / 4 +1);
        a_note = song_notes[index++];
    }
}

/**
 * The method can make the sound for a note.
 * Args:
 * frequency: the frequency of the note.
 * duration: the length of the note.
 */
static void tone(uint32_t frequency, uint32_t duration) {
    set_timer_pointer(TIM3_BASE);
    uint32_t arr_val = 16000000 / (2 * frequency); // calculate the number of ticks that arr should have.
    set_ccr1(0);
    set_arr(arr_val);

    enable_output(); // start making sound.
    start_counter();
    delay_ms(duration);
    disable_output(); // stop making sound.
    stop_counter();
}


