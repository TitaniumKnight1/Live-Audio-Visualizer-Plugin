# Installation Guide - OBS Live Audio Visualizer Plugin

## For Non-Technical Users

Follow these simple steps to install the plugin on Windows:

### Step 1: Download the Plugin Files

1. Go to [Releases](https://github.com/TitaniumKnight1/OBS-Live-Audio-Visualizer-Plugin/releases)
2. Click on the latest release
3. Download both files:
   - `audio-visualizer.dll`
   - `en-US.ini`

### Step 2: Install the DLL (binary)

**Windows users:**

1. Press `Win + R` on your keyboard
2. Copy and paste this path:
   ```
   C:\Program Files\obs-studio\obs-plugins\64bit
   ```
3. Press Enter

Drag and drop `audio-visualizer.dll` into this folder (alongside other plugin `.dll` files).

### Step 3: Install the locale file (menu / property names)

OBS loads translated strings from the plugin **data** folder, **not** from the `64bit` folder.

1. Press `Win + R` again and open:
   ```
   C:\Program Files\obs-studio\data\obs-plugins
   ```
2. Create a folder named exactly: `audio-visualizer`
3. Inside it, create a folder named exactly: `locale`
4. Copy `en-US.ini` into:
   ```
   C:\Program Files\obs-studio\data\obs-plugins\audio-visualizer\locale\en-US.ini
   ```

**Portable OBS:** use `<your OBS folder>\data\obs-plugins\audio-visualizer\locale\en-US.ini` instead.

**Your layout should look like this:**

```
C:\Program Files\obs-studio\
├── obs-plugins\64bit\
│   └── audio-visualizer.dll
└── data\obs-plugins\audio-visualizer\
    └── locale\
        └── en-US.ini
```

If `en-US.ini` is missing or in the wrong directory, OBS shows keys such as `KickViz.SourceName` instead of human-readable labels. Putting the file under `obs-plugins\64bit\...\locale` does **not** work.

### Step 4: Restart OBS

1. **Close OBS completely** (if it is open)
2. **Open OBS Studio again**
3. The plugin is now installed!

## How to Use the Plugin

1. Open OBS Studio
2. In your Scene, click the **`+`** button under **Sources**
3. Select **"Audio Visualizer"** from the list
4. Choose your audio source (usually "Desktop Audio" or your microphone)
5. Customize the visualization with the settings panel

## Troubleshooting

### Plugin doesn't appear in OBS

**Solution:**
- Make sure you have OBS Studio **31.1.1 or newer**
- Check that the DLL is in: `C:\Program Files\obs-studio\obs-plugins\64bit\`
- Restart OBS after installation

### Audio isn't showing

**Solution:**
- Make sure you selected an audio source in the plugin settings
- Check that audio is actually playing
- Try increasing the "Sensitivity" slider in the plugin settings

### Text labels are missing or show `KickViz.*` keys

**Solution:**
- Install `en-US.ini` under the **data** path (see Step 3), for example:
  ```
  C:\Program Files\obs-studio\data\obs-plugins\audio-visualizer\locale\en-US.ini
  ```
- If OBS is set to a language other than English, it still falls back to `en-US.ini` when no matching file exists—as long as that file is in this folder.

## Need Help?

If you are still having issues:
1. Check that you are using the **latest version** of OBS Studio
2. Verify the DLL and locale paths above
3. Open an issue on [GitHub](https://github.com/TitaniumKnight1/OBS-Live-Audio-Visualizer-Plugin/issues)

## For Advanced Users / Developers

If you want to build the plugin from source, see the [README.md](README.md) for build instructions.
