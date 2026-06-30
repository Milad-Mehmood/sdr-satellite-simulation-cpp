// This file is the property of Milad Mehmoody Zargar.
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.

// This file is the main entry point for the SDR satellite simulation.
// It imports the necessary functions from transmitter.py
// and executes the simulation by generating a random data stream,
// modulating it using BPSK, and printing the results.

# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>

# include "transmitter.hpp"

int main()
{
    std::cout << "\n SDR C++ simulation started, initializing components... \n" << std::endl;

    /*  Current time changes every second.
        So srand(time(...)) gives rand() a different starting point/seed.
        Different starting point → different random sequence.
        Different random sequence → different bit stream. */
    srand(static_cast<unsigned int>(time(nullptr)));

    int bit_length = 10;
    std::vector<int> bits = generate_bits(bit_length);

    test_transmitter();

    for ( int bit : bits)
    {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    return 0;
}