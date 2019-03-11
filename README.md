[![Build Status](https://img.shields.io/travis/serverzone/Kea-dhcp-hooks.svg?style=flat-square)](https://travis-ci.org/serverzone/Kea-dhcp-hooks)

# Kea-dhcp-hooks
Kea DHCP hooks:
* **mac2ipv6** - select IPv6 address via mac address

Compatible with Kea 1.1.0.

## Require

* cmake
* boost
* google test

Note: After you installing the gtest development package you have to compile the code yourself to create
the necessary library files.

```bash
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo make install
```

## How to build

```bash
mkdir -p build
cd build
cmake ..
make
test/tests
sudo make install
```

## How to use mac2ipv6

Example of configuration:
```json
{
  "Dhcp6": {
    "hooks-libraries": [
        {
            "library": "/usr/local/lib/kea/hooks/libmac2ipv6.so",
            "parameters": {
                "client-classes": [ "b-efi" ]
            }
        }
    ],
    ...
}
```

MAC address-based IP address settings can be restricted to `client-class` clients only by using the
client-classes parameter. If the parameter is not listed or contains a blank field, the hook is applied
to all client classes.
