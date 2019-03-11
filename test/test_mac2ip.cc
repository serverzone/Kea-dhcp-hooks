#include <gtest/gtest.h>
#include "mac2ip.h"

TEST(MacToIp, IPv6_1) {
    uint8_t u[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
    std::vector<uint8_t> mac_addr(u, u + sizeof(u) / sizeof(uint8_t) );
    std::vector<uint8_t> remote_addr(16, 0x64);

    EXPECT_EQ("6464:6464:6464:6464:0302:03ff:fe04:0506", mac2ipv6(mac_addr, remote_addr));
}

TEST(MacToIp, IPv6_2) {
    std::vector<uint8_t> mac_addr(6, 0x1a);
    std::vector<uint8_t> remote_addr(16, 0x32);

    EXPECT_EQ("3232:3232:3232:3232:181a:1aff:fe1a:1a1a", mac2ipv6(mac_addr, remote_addr));
}

TEST(MacToIp, IPv6_3) {
    std::vector<uint8_t> mac_addr(6, 0x01);
    std::vector<uint8_t> remote_addr(16, 0xa0);

    EXPECT_EQ("a0a0:a0a0:a0a0:a0a0:0301:01ff:fe01:0101", mac2ipv6(mac_addr, remote_addr));
}