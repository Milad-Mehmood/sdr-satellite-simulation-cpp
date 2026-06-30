// Copyright (c) 2026 Milad Mehmood Zargar.
// All rights reserved.

// Channel module.
// Provides functions to simulate transmission effects such as noise.

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

# include <vector>

std::vector<double> add_noise(std::vector<int>& symbols);

#endif // CHANNEL_HPP