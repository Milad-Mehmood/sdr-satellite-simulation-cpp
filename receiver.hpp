// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Receiver module.
// Provides functions to recover bits from received/noisy symbols.

# ifndef RECEIVER_HPP
# define RECEIVER_HPP

# include <iostream>
# include <vector>

std::vector<int> bpsk_demodulation(const std::vector<double>& received_signal);
double calculate_ber(const std::vector<int> original_bits, const std::vector<int> recovered_bits);


# endif // RECEIVER_HPP