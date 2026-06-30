// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Transmitter module.
// Provides functions for generating bit streams and applying modulation.

# ifndef TRANSMITTER_HPP
# define TRANSMITTER_HPP

# include <vector>

void test_transmitter();
std::vector<int> generate_bits(int number_of_bits);
std::vector<int> bpsk_modulate(const std::vector<int>& bits);

#endif // TRANSMITTER_HPP
