// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Channel module.
// Provides functions to simulate transmission effects such as noise.

# include <iostream>
# include <vector>
# include <cstdlib>

# include "channel.hpp"

std::vector<double> add_noise(std::vector<int>& symbols)
{
    std::vector<double> noisy_signal;
    
    for ( int symbol : symbols)
    {
        double noise = ((static_cast<double>(rand()) / RAND_MAX) - 0.5) * 1.0;
        noisy_signal.push_back(symbol + noise);
    }
    return noisy_signal;
}
