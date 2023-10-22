/* Copyright 2023, Darran A Lofthouse
 *
 * This file is part of pico-hmac-test.
 *
 * pico-sha-test is free software: you can redistribute it and/or modify it under the terms 
 * of the GNU General Public License as published by the Free Software Foundation, either 
 * version 3 of the License, or (at your option) any later version.
 *
 * pico-sha-test is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with pico-sha-test.
 * If  not, see <https://www.gnu.org/licenses/>. 
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"

#include "util/binaryutil.h"
#include "util/hexutil.h"
#include "util/systick.h"
#include "security/hotp.h"

#include "pico-otp-data.h"

void hotp_test(char *raw_secret, struct data_element *the_data)
{
    char otp[6];

    start_syst_counter();
    calculate_hotp(raw_secret, 20, the_data->count, otp);
    uint32_t ticks = stop_syst_counter();

    char *expected_hotp = the_data->hotp;
    bool success = true;

    for (short i = 0; i < 6 && success; i++)
    {
        char expected = expected_hotp[i] - 0x30;
        char actual = otp[i];
        success = expected == actual;
    }
    uint32_t test_count = (uint32_t) the_data->count;

    printf("| %*d | %*s | %*d |\n", 5, test_count, 11, success ? "Pass" : "Fail", 15, ticks);
}


int main()
{
    stdio_init_all();

    char *hex_secret = "3132333435363738393031323334353637383930";    

    char raw_secret[20];
    for (short byte = 0; byte < 20; byte++)
    {
        raw_secret[byte] = hex_to_char(&hex_secret[byte * 2]);
    }

    printf("\n\n\nBegin HOTP Testing\n\n");

    printf("+-------+-------------+-----------------+\n");
    printf("| Test  | Pass / Fail | Syst Tick Count |\n");
    printf("+-------+-------------+-----------------+\n");
    
    for (short test = 0; test < 10 ; test++ ) {
        struct data_element current_element = otp_tests[test];
        hotp_test(raw_secret, &current_element);        
    }

    printf("+-------+-------------+-----------------+\n");
}

#ifdef LOG_DATA
void log_data(char * data, uint32_t length) {
    short word_pos = 4;
    short word_count = 0;

    printf("* * Data * * \n");
    char temp_hex[9];
    temp_hex[8] = 0;
    for (uint32_t i = 0 ; i < length ; i++) {
        uint32_t temp_byte = data[i];
        uint32_to_hex(temp_byte, temp_hex);
        printf("%s", &temp_hex[6]);
        word_pos = (word_pos + 1) % 4;
        if (word_pos == 0) {
            word_count = (word_count + 1) % 20;
            if (word_count == 0) {
                printf("\n");
            } else {
            printf(" ");                
            }
        }
    }

    printf("\n");
}
#endif

#ifdef LOG_ARRAY
void log_words(uint32_t * words) {
    char binary_result[32];    
    short this_row_count = 0;

    printf("\n\nBinary Output\n\n");
    for (uint32_t word_pos = 0 ; word_pos <= 79 ; word_pos++) {
        int_to_binary(words[word_pos], binary_result);

        for (short pos = 0 ; pos < 32 ; pos++) {
            putchar(binary_result[pos]);
            if ((pos + 1) % 8 == 0) {
                putchar(' ');
            }
        }

        this_row_count = (this_row_count + 1) % 4;
        if (this_row_count == 0) {
            printf("\n");
        }
    }
}
#endif
