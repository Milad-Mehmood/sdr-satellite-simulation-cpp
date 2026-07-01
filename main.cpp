// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// This file is the main entry point for the SDR satellite simulation.
// It imports the necessary functions from transmitter.cpp
// and executes the simulation by generating a random data stream,
// modulating it using BPSK, and printing the results.

# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>

# include "transmitter.hpp"
# include "channel.hpp"
# include "receiver.hpp"

int main()
{
    std::cout << "\n SDR C++ simulation started, initializing components... \n" << std::endl;
    test_transmitter();

    /*  Current time changes every second.
        So srand(time(...)) gives rand() a different starting point/seed.
        Different starting point → different random sequence.
        Different random sequence → different bit stream. */
    srand(static_cast<unsigned int>(time(nullptr)));

    int bit_length = 10;
    std::vector<int> bits = generate_bits(bit_length);
    std::vector<int> bpsk_symbols = bpsk_modulate(bits);
    std::vector<double> noisy_signal = add_noise(bpsk_symbols);
    std::vector<int> received_bits = bpsk_demodulation(noisy_signal);
    double ber = calculate_ber(bits, received_bits);

    for ( int bit : bits)
    {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    for ( int symbol : bpsk_symbols)
    {
        std::cout << symbol << " ";
    }
    std::cout << std::endl;

    for ( double noisy_symbol : noisy_signal)
    {
        std::cout << noisy_symbol << " ";
    }
    std::cout << std::endl;

    for ( int recovered_bit : received_bits)
    {
        std::cout << recovered_bit << " ";
    }
    std::cout << std::endl;
    std::cout << "BER: " << ber << std::endl;

    

    return 0;
}