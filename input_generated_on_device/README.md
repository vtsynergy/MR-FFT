Includes HLS Code and jupyter notebook for FFT 8000
Input is generated on device. \
    Input is a sinewave sin(2*pi*100/8000). Input is generated in fp32 and converted to ap_fixed(24,2) - 2  bits reserved for integer part. \
    PL computes FFT-8000 on ap-fixed(24,2) data, casts the result back to fp32 and writes the data on DMA out stream to the host. \
	
	Users need to compile the code in Vitis HLS and generate the IP for it in VIVADO
