// This file is the property of Milad Mehmoody Zargar.
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.

// file transmitter.py, here we have to define the transmitter functions, which are responsible for generating data streams to the receiver.
// Need to check this line: "The transmitter will handle the encoding of data, error checking, and managing the transmission protocol."

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
