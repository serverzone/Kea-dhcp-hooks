#ifndef MAC2IP_H
#define MAC2IP_H

#include <vector>
#include <string>

extern "C" {

extern std::string mac2ipv6(const std::vector<uint8_t> mac_addr, const std::vector<uint8_t> remote_addr);

}

#endif // not defined MAC2IP_H