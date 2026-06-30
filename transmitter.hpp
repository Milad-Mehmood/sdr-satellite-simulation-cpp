// This file is the property of Milad Mehmoody Zargar.
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.

// Transmitter functions for handling data transmission

# ifndef TRANSMITTER_HPP
# define TRANSMITTER_HPP

# include <vector>

void test_transmitter();
std::vector<int> generate_bits(int number_of_bits);
std::vector<int> bpsk_modulate(const std::vector<int>& bits);

#endif // TRANSMITTER_HPP
