#ifndef GGWAVE_ESP_IDF_H
#define GGWAVE_ESP_IDF_H

#include "ggwave/ggwave.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int payloadLength;              // Desired payload length (e.g., 16)
    int sampleRate;                 // Audio sample rate (e.g., 24000)
    int samplesPerFrame;            // Samples per frame (e.g., 512, must be power of 2)
    ggwave_SampleFormat sampleFormatInp; // Input sample format
    int operatingMode;              // GGWave operating mode
} ggwave_esp_idf_config_t;

/**
 * @brief Get default configuration for ESP-IDF
 * 
 * @return ggwave_esp_idf_config_t 
 */
ggwave_esp_idf_config_t ggwave_esp_idf_default_config(void);

/**
 * @brief Initialize GGWave instance with the given configuration.
 * 
 * @param config Configuration parameters.
 * @return ggwave_Instance The initialized instance id, or -1 on failure.
 */
ggwave_Instance ggwave_esp_idf_init(const ggwave_esp_idf_config_t *config);

/**
 * @brief Decode audio samples from a buffer.
 * 
 * This function wraps ggwave_ndecode and is intended to be used with
 * audio buffers coming from I2S or other sources.
 * 
 * @param instance GGWave instance id.
 * @param waveformBuffer Pointer to the audio samples.
 * @param waveformSize Size of the audio samples in bytes.
 * @param payloadBuffer Buffer to store decoded data.
 * @param payloadSize Maximum size of the payloadBuffer.
 * @return int Number of decoded bytes, 0 if no data, negative on error.
 */
int ggwave_esp_idf_decode(ggwave_Instance instance,
                          const void *waveformBuffer, int waveformSize,
                          void *payloadBuffer, int payloadSize);

#ifdef __cplusplus
}
#endif

#endif // GGWAVE_ESP_IDF_H
