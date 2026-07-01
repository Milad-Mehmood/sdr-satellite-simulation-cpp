// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Receiver module.
// Provides functions to recover bits from received/noisy symbols.

# include <iostream>
# include <vector>
# include "receiver.hpp"


std::vector<int> bpsk_demodulation(const std::vector<double>& received_signal)
{
    std::vector<int> recovered_bits;
    for ( double received_symbol : received_signal )
    {
        recovered_bits.push_back((received_symbol >= 0.0) ? 1 : 0 );
    }
    return recovered_bits;
}

double calculate_ber(const std::vector<int> original_bits, const std::vector<int> recovered_bits)
{
    int error_count = 0;
    for ( int i = 0 ; i < original_bits.size() ; i++ )
    {
        if ( original_bits != recovered_bits )
        {
            error_count++;
        }
    }
    return static_cast<double>(error_count)/original_bits.size();
}