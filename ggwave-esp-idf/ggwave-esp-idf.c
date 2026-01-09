#include "ggwave-esp-idf.h"
#include <string.h>

ggwave_esp_idf_config_t ggwave_esp_idf_default_config(void) {
  ggwave_esp_idf_config_t config = {.payloadLength = 64,
                                    .sampleRate = 24000,
                                    .samplesPerFrame = 512,
                                    .sampleFormatInp = GGWAVE_SAMPLE_FORMAT_I16,
                                    .operatingMode =
                                        GGWAVE_OPERATING_MODE_RX |
                                        GGWAVE_OPERATING_MODE_USE_DSS};
  return config;
}

ggwave_Instance ggwave_esp_idf_init(const ggwave_esp_idf_config_t *config) {
  if (config == NULL) {
    return -1;
  }

  ggwave_Parameters params = ggwave_getDefaultParameters();

  params.payloadLength = config->payloadLength;
  params.sampleRateInp = (float)config->sampleRate;
  params.sampleRateOut = (float)config->sampleRate;
  params.sampleRate = (float)config->sampleRate;
  params.samplesPerFrame = config->samplesPerFrame;
  params.sampleFormatInp = config->sampleFormatInp;
  params.sampleFormatOut = GGWAVE_SAMPLE_FORMAT_U8;
  params.operatingMode = config->operatingMode;

  return ggwave_init(params);
}

int ggwave_esp_idf_decode(ggwave_Instance instance, const void *waveformBuffer,
                          int waveformSize, void *payloadBuffer,
                          int payloadSize) {
  if (instance < 0) {
    return -1;
  }

  // ggwave_ndecode returns the number of decoded bytes, 0 if none,
  // -1 on error, or -2 if payloadBuffer is too small.
  return ggwave_ndecode(instance, waveformBuffer, waveformSize, payloadBuffer,
                        payloadSize);
}