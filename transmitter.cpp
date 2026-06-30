// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Transmitter module.
// Provides functions for generating bit streams and applying modulation.

# include <iostream>
# include <cstdlib>
# include "transmitter.hpp"

void test_transmitter()
{
    std::cout << "\n Transmitter file connected \n" << std::endl;
}

std::vector<int> generate_bits(int number_of_bits)
{
    std::vector<int> bis;
    for ( int i = 0 ; i < number_of_bits ; i++)
    {
        bis.push_back(rand()%2);
    }
    return bis;
}

std::vector<int> bpsk_modulate(const std::vector<int>& bits)
{
    std::vector<int> bpsk_symbols;

    for (int bit : bits)
    {
        bpsk_symbols.push_back(( bit == 0 ) ? -1 : 1 );
    }

    return bpsk_symbols;
}
