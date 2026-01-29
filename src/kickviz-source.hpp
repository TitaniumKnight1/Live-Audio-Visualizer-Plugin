#pragma once
#include <obs-module.h>
#include <atomic>
#include <mutex>
#include <vector>
#include <string>

struct KickVizSettings {
  std::string audio_source_name;

  int mode = 0;           // 0=Normal, 1=Mirrored, 2=Radial, 3=Sym-Radial
  int shape = 0;          // 0=Square, 1=Rounded, 2=Capsule, 3=Dots, 4=Line
  int freq_range = 1;     // 0=Bass(LowDetail), 1=Standard, 2=Wide, 3=Full

  uint32_t color = 0xFFFFFFFF;   // RGBA
  uint32_t bg_color = 0x00000000;
  bool use_gradient = false;
  uint32_t color2 = 0xFF00FFFF;

  float magnitude = 1.0f;        // height multiplier (default 1.0)
  float sensitivity = 1.25f;     // multiplier
  float smoothing = 0.55f;       // 0..0.95
  float decay = 0.12f;           // 0..1 (peak fall)
  int bar_width = 10;
  int gap = 3;

  bool use_base_size = true;
  int width = 1920;
  int height = 1080;
};

struct KickVizState {
  obs_source_t *context = nullptr;

  // Target audio source (ref-counted when held)
  obs_source_t *audio_source = nullptr;

  // Audio ring buffer (mono float)
  std::mutex audio_mtx;
  std::vector<float> ring;
  size_t ring_write = 0;
  int sample_rate = 48000;

  // Render data
  std::vector<float> window;     // FFT window input
  std::vector<float> mags;       // magnitudes (bins)
  std::vector<float> smooth;     // smoothed bins
  std::vector<float> peaks;      // peak caps

  // 1x1 texture for drawing quads
  gs_texture_t *white_tex = nullptr;

  KickVizSettings S;
};