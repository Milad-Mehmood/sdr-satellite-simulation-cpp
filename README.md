# SDR Satellite Simulation in C++

This project simulates a basic Software Defined Radio (SDR) signal chain in C++.

Signal chain:

bits → BPSK modulation → noisy channel → BPSK demodulation → BER calculation

## How to Run

Compile the project:

```bash
g++ main.cpp transmitter.cpp channel.cpp receiver.cpp -o sdr_sim
```

Run:

```bash
./sdr_sim
```
