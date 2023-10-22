# pico-otp-test
Test program to create and verify numerous HOTP calculations on a Raspberry Pi Pico

## Cloning the project.

Checkout the project using the following command:

    git clone --recurse-submodules https://github.com/darranl/pico-otp-test.git

## Building the project.

This assmumes you have already set up a working environment based on the [Getting Started with Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) documentation at [raspberrypi.com](https://www.raspberrypi.com).

    cd pico-otp-test
    mkdir build
    cd build
    cmake ..
    make -j4

After this there will be two binaries which can be installed depending on your installation mechanism `pico-otp-test.elf` or `pico-otp-test.uf2`.

Once installed the test program runs immidiately and outputs the results to `stdio`.

e.g.
    Begin HOTP Testing

    +-------+-------------+-----------------+
    | Test  | Pass / Fail | Syst Tick Count |
    +-------+-------------+-----------------+
    |     0 |        Pass |           54142 |
    |     1 |        Pass |           45554 |
    |     2 |        Pass |           44196 |
    |     3 |        Pass |           43989 |
    |     4 |        Pass |           43889 |
    |     5 |        Pass |           43787 |
    |     6 |        Pass |           43688 |
    |     7 |        Pass |           43687 |
    |     8 |        Pass |           43689 |
    |     9 |        Pass |           43687 |
    +-------+-------------+-----------------+



