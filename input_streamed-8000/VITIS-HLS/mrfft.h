#ifndef _MMULT_
#define _MMULT_

#include "ap_axi_sdata.h"
#include "ap_int.h"
#include <inttypes.h>
//#include "hls_fft.h"
#include <complex>

const char FFT_NFFT_MAX = 6;
const int FFT_LENGTH1 = 1 << FFT_NFFT_MAX;
const int FFT_LENGTH2 = 125;
const int TWO_FFT_LENGTH1 = 128;

//#include "hls_fft.h"

// configurable params
//const char FFT_INPUT_WIDTH = 32;
//const char FFT_OUTPUT_WIDTH = FFT_INPUT_WIDTH;
//const char FFT_CONFIG_WIDTH = 16;
//const char FFT_NFFT_MAX22 = 13;
//const int FFT_LENGTH = 1 << FFT_NFFT_MAX22;

/*
struct config1 : hls::ip_fft::params_t {
    static const unsigned ordering_opt = hls::ip_fft::natural_order;
   // static const unsigned ordering_opt = hls::ip_fft::bit_reversed_order;
    static const unsigned config_width = FFT_CONFIG_WIDTH;
    static const unsigned phase_factor_width = 24;
    static const unsigned max_nfft = 13;
    static const unsigned stages_block_ram = 4;
    static const unsigned mem_data = hls::ip_fft::distributed_ram;
    static const unsigned mem_phase_factors=hls::ip_fft::distributed_ram;
    static const unsigned mem_reorder=hls::ip_fft::distributed_ram;
    static const bool mem_hybrid=true;
    static const unsigned butterfly_type=hls::ip_fft::use_xtremedsp_slices;
    //static const bool ovflo =false;
    //static const unsigned complex_mult_type= hls::ip_fft::use_luts;

};

typedef hls::ip_fft::config_t<config1> config_t;
typedef hls::ip_fft::status_t<config1> status_t;
*/
//typedef float data_in_t;
//typedef float data_out_t;
//typedef ap_fixed<FFT_INPUT_WIDTH, 1> data_in_t;
//typedef ap_fixed<FFT_OUTPUT_WIDTH, FFT_OUTPUT_WIDTH - FFT_INPUT_WIDTH + 1>
//    data_out_t;


//typedef std::complex<data_in_t> cmpxDataIn;
//typedef std::complex<data_out_t> cmpxDataOut;




//configurable params
/*
const char FFT_INPUT_WIDTH = 16;
const char FFT_OUTPUT_WIDTH = FFT_INPUT_WIDTH;
const char FFT_CONFIG_WIDTH = 8;
*/

/*
struct config1 : hls::ip_fft::params_t{
    static const unsigned ordering_opt = hls::ip_fft::natural_order;
	//static const unsigned ordering_opt = hls::ip_fft::bit_reversed_order;
    static const unsigned config_width = FFT_CONFIG_WIDTH;
    static const unsigned max_nfft = FFT_NFFT_MAX;
    static const unsigned phase_factor_width = 24;
};

typedef hls::ip_fft::config_t<config1> config_t;
typedef hls::ip_fft::status_t<config1> status_t;
*/
#define N 128
#define N2 3200 //
#define HALF_N2 1600

//#define N2 16394 //
//#define HALF_N2 8192

#define DWIDTH 512
typedef ap_axiu<DWIDTH, 0, 0, 0> axis_t;

typedef ap_uint<512> uint512_t;
typedef float DataType2;

typedef ap_fixed<24,2,AP_RND_CONV> DataType;
//typedef ap_fixed<1,23,AP_RND_CONV> DataType;
//typedef float DataType;
const int DataTypeSize = sizeof(DataType2) * 8;

typedef ap_uint<DataTypeSize> DataTypeInt;

typedef union converter {
  DataType2 d;
  uint32_t i;
} converter_t;


//template <typename T> void kernel_dft(T a[N2], T c[N2]);
//template <typename T> void kernel_dft(T a[N2]);
template <typename T> void kernel_dft(DataType2 a[N2]);
//void kernel_dft(DataType a[N2], DataType c[N2]);
//template <typename T> void kernel_mmult(T a[N2], T c[N2]);

#endif
