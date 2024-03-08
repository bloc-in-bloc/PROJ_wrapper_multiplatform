# PROJ wrapper multiplateform

This projects provides a C wrapper and a CMake configuration to build native libraries with proj for following platforms:

- macOS Universal (Intel and Apple Silicon)
- Windows 64-bit
- iOS (arm64 and armv7a)
- Android (arm64-v8a and armeabi-v7a)

## How to use on mac

Open projet with `JetBrains CLion` and import CMakePresets.

## How to use on windows

Generate project with cmake :

```
cmake . -G 'Visual Studio 17 2022'
```

And import CMakePresets.