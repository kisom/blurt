#ifndef OFDM_H
#define OFDM_H
#include "blurt.h"
#include "scrambler.h"

class OFDMFormat {
public:
    size_t nfft, ncp, ts_reps, Nsc, Nsc_used, preambleLength;
    std::vector<complex> sts_freq, sts_time, lts_freq, lts_time;
    std::vector<size_t> dataSubcarriers, pilotSubcarriers;
    std::vector<complex> pilotTemplate;
};

OFDMFormat audioLTFormat();

class PilotPolarity {
private:
    Scrambler sc;
public:
    PilotPolarity();
    complex next();
};

class OFDM {
public:
    OFDMFormat format;
    OFDM(const OFDMFormat &format);
    void encode(const std::vector<complex> &input, std::vector<complex> &output) const;
};
#endif
