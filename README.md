# Unity Plugin Example

This projects provides a C wrapper and a CMake configuration to build native libraries for following platforms:

- macOS Universal (Intel and Apple Silicon)
- Windows 64-bit
- Universal Windows Platform (x86,x64,arm and arm64)
- Linux x86_64
- iOS (arm64 and armv7a)
- Android (arm64-v8a and armeabi-v7a)

# Generate XCode for mac

```
cmake . -G Xcode -B build_mac -DCMAKE_OSX_ARCHITECTURES="x86_64;arm64"
```

# Generate XCode for ios

```
cmake . -G Xcode -B build_ios -G Xcode -DCMAKE_SYSTEM_NAME=iOS -DPLUGIN_EMBED_BITCODE=ON
```