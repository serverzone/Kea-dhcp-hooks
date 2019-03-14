[![Build Status](https://img.shields.io/travis/serverzone/Kea-dhcp-hooks.svg?style=flat)](https://travis-ci.org/serverzone/Kea-dhcp-hooks)
[![GitHub issues](https://img.shields.io/github/issues/serverzone/Kea-dhcp-hooks.svg?style=flat)](https://github.com/serverzone/Kea-dhcp-hooks/issues)
[![License](https://img.shields.io/github/license/serverzone/Kea-dhcp-hooks.svg?style=flat)](https://github.com/serverzone/Kea-dhcp-hooks)

# Kea-dhcp-hooks

Compatible with Kea 1.1.0.

## Hooks

### mac2ipv6 hook

Generates and returns the same address as a device would have generated via SLAAC. A use case for this is to return a statefull like address in a stateless network. In our case, UEFI requires a statefull DHCPv6 response, but we don't want to have statefull DHCPv6 it our network.

This hook works properly only in a network with a DHCPv6 relay. When there is no link address forwarded (issue with mikrotik) an error is logged.

This hook doesn't work with devices connected to the same network as dhcpv6 server.

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
bin/compile.sh
cd build
test/tests
sudo make install
```
