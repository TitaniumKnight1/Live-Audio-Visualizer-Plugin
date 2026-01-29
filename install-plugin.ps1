# Audio Visualizer Plugin Installer
$ErrorActionPreference = "Stop"

Write-Host "=== Audio Visualizer Plugin Installer ===" -ForegroundColor Cyan

$obsProcess = Get-Process "obs64" -ErrorAction SilentlyContinue
if ($obsProcess) {
    Write-Host "ERROR: OBS is running. Please close OBS and run this script again." -ForegroundColor Red
    exit 1
}

$pluginDll = "build_x64\RelWithDebInfo\audio-visualizer.dll"
$dataDir = "build_x64\rundir\RelWithDebInfo\audio-visualizer"
$obsPluginDir = "C:\Program Files\obs-studio\obs-plugins\64bit"
$obsDataDir = "C:\Program Files\obs-studio\data\obs-plugins\audio-visualizer"

Write-Host "Copying plugin DLL..."
Copy-Item $pluginDll $obsPluginDir -Force
Write-Host "  Copied: $obsPluginDir\audio-visualizer.dll" -ForegroundColor Green

Write-Host "Copying plugin data files..."
if (Test-Path $dataDir) {
    New-Item -ItemType Directory -Force -Path $obsDataDir | Out-Null
    Copy-Item -Path "$dataDir\*" -Destination $obsDataDir -Recurse -Force
    Write-Host "  Copied locale files to: $obsDataDir" -ForegroundColor Green
} else {
    Write-Host "  Warning: No data directory found" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "Installation complete! You can now start OBS." -ForegroundColor Green
