#include <obs-module.h>
#include "plugin-support.h"
#include "kickviz-source.hpp"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

MODULE_EXPORT const char *obs_module_description(void)
{
  return "Audio Visualizer - Real-time audio-reactive visualization with dynamic bars";
}

extern obs_source_info kickviz_source_info;
extern void kickviz_register_source(void);

bool obs_module_load(void)
{
  kickviz_register_source();
  obs_register_source(&kickviz_source_info);
  blog(LOG_INFO, "[audio-visualizer] plugin loaded successfully (version %s)", PLUGIN_VERSION);
  return true;
}

void obs_module_unload(void)
{
  blog(LOG_INFO, "[audio-visualizer] plugin unloaded");
}