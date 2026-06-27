// This file is the property of Milad Mehmoody Zargar.
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.

// This file is the main entry point for the SDR satellite simulation.
// It imports the necessary functions from transmitter.py
// and executes the simulation by generating a random data stream,
// modulating it using BPSK, and printing the results.

# include <iostream>
# include "transmitter.hpp"

int main()
{
    std::cout << "\n SDR C++ simulation started, initializing components... \n" << std::endl;
    test_transmitter();
    return 0;
}