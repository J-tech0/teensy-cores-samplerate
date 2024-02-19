/*  J-tech0
    Teensy audio but with the sample rate parameterised for convenience
    19/02/2024
*/

#ifndef AudioParams_h
#define AudioParams_h


#define SAMPLE_RATE_PARAM 48000


#if SAMPLE_RATE_PARAM == 48000
    #define AUDIO_SAMPLE_RATE_EXACT 48000.0f            //AudioStream.h, sample rate
    #define AUDIO_TX_SIZE         192                   //usb_desc.h, buffer size dependent on sample rate, 4*48
    #define AUDIO_RX_SIZE         192
    #define USB_AUDIO_FEEDBACK_ACCUMULATOR 805306368    //usb_audio.cpp, feedback_accumulator, 2^24*48khz
    #define USB_AUDIO_SAMPLE_RATE_TARGET 48000          //usb_audio.cpp, USB buffer target
    #define AUDIO_INTERFACE_BUFFER 48000                //usb_audio.cpp, usb.c
    #define USB_DESC_SAMPLERATE 48000                   //usb_desc.c
#else /*default 44100, or any other value provided reverts to default*/
    #define AUDIO_SAMPLE_RATE_EXACT 44100.0f            //AudioStream.h, sample rate
    #define AUDIO_TX_SIZE         180                   //usb_desc.h, buffer size dependent on sample rate, 4*45
    #define AUDIO_RX_SIZE         180
    #define USB_AUDIO_FEEDBACK_ACCUMULATOR 739875226    //usb_audio.cpp, feedback_accumulator, 2^24*44.1khz
    #define USB_AUDIO_SAMPLE_RATE_TARGET 44100          //usb_audio.cpp, USB buffer target
    #define AUDIO_INTERFACE_BUFFER 44100                //usb_audio.cpp, usb.c
    #define USB_DESC_SAMPLERATE 44100                   //usb_desc.c
#endif




#endif