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

int getBitLength()
{
    int bitLength = 0;
    std::cout << "Enter the bit length: ";
    std::cin >> bitLength;
    return bitLength;
}

int getBitPrintLength(int bit_length)
{
    int printLength = 0;
    std::cout << "Enter the bit length to be printed: ";
    while(1)
    {
        std::cin >> printLength;
        if (bit_length < printLength)
        {
            std::cout << "\nPrint Length can't be more than Bit Length, please enter a valid value." << std::endl;
        }
        else
        {
            break;
        }
    }
    return printLength;
}

double getNoiseStrength()
{
    double noiseStrength = 0;
    std::cout << "Enter the channel noise strength: ";
    std::cin >> noiseStrength;
    return noiseStrength;
}

void print_first_values(const std::vector<int>& values, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << values[i] << " ";
    }

    std::cout << "\n";
}

void print_first_values_double(const std::vector<double>& values, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << values[i] << " ";
    }

    std::cout << "\n";
}

int main()
{
    std::cout << "\n SDR C++ simulation started, initializing components... \n" << std::endl;
    test_transmitter();

    /*  Current time changes every second.
        So srand(time(...)) gives rand() a different starting point/seed.
        Different starting point → different random sequence.
        Different random sequence → different bit stream. */
    srand(static_cast<unsigned int>(time(nullptr)));

    int bit_length = getBitLength();
    int bit_printLength = getBitPrintLength(bit_length);
    double noiseStrength = getNoiseStrength();
    std::vector<int> bits = generate_bits(bit_length);
    std::vector<int> bpsk_symbols = bpsk_modulate(bits);
    std::vector<double> noisy_symbols = add_noise(bpsk_symbols, noiseStrength);
    std::vector<int> received_bits = bpsk_demodulation(noisy_symbols);
    double ber = calculate_ber(bits, received_bits);

    std::cout << "\nBits: " << std::endl;
    print_first_values(bits, 10);

    std::cout << "\nBPSK Symbols: " << std::endl;
    print_first_values(bpsk_symbols, 10);

    std::cout << "\nNoisy Signal: " << std::endl;
    print_first_values_double(noisy_symbols, 10);

    std::cout << "\nRecovered Bits: " << std::endl;
    print_first_values(received_bits, 10);

    std::cout << "\nBER: " << ber << std::endl;

    

    return 0;
}