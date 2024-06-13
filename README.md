# Description
Example for [vcpkg-base](https://github.com/sunzhenkai/vcpkg-base).

# Build
```
cmake --preset=default
cmake --build vcpkg-build
```

# Overlay Port
```shell
vcpkg install {port} --overlay-ports=/path/to/source/overlay-port

# for example
vcpkg install datastax-cpp-driver --overlay-ports=/data/code/vcpkg-base-example/overlay-port
vcpkg install babylon --overlay-ports=/data/code/vcpkg-base-example/overlay-port
vcpkg install polaris-cpp --overlay-ports=/data/code/vcpkg-base-example/overlay-port
vcpkg install opentelemetry-cpp --overlay-ports=/data/code/vcpkg-base-example/overlay-port
```