/* Copyright 2023, Darran A Lofthouse
 *
 * This file is part of pico-otp-test.
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

#include <stdlib.h>

struct data_element {
    u_int64_t count;
    char *hotp;
};

struct data_element otp_tests[] =
    {
        {0, "755224"},
        {1, "287082"},
        {2, "359152"},
        {3, "969429"},
        {4, "338314"},
        {5, "254676"},
        {6, "287922"},
        {7, "162583"},
        {8, "399871"},
        {9, "520489"}};