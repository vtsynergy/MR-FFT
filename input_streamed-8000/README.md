HLS code and and jupyter notebook for FFT 8000
Input is generated on host and is streamed to the programmable logic. \
    Input format on host is fp32. \
    PL reads the stream  of fp32 data using DMA IP and casts it to ap_fixed(24,2) format(24 bit wide data, 2 bits reserved for integer part)
    PL computes FFT-8000 on ap-fixed(24,2) data, casts the result back to fp32 and writes the data on DMA out stream to the host. \
