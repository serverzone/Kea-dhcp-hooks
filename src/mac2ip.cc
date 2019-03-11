#include <sstream>
#include <iomanip>
#include "mac2ip.h"

extern "C" {

std::string mac2ipv6(const std::vector<uint8_t> mac_addr, const std::vector<uint8_t> remote_addr) {

    std::ostringstream oss;

    // prefix from remote address
    for (unsigned i=0; i<remote_addr.size()-mac_addr.size()-2; i++) {
        uint8_t u = remote_addr.at(i);

        oss << std::setfill('0') << std::setw(2) << std::hex << (uint16_t)u;
        if (i % 2) {
            oss << ":";
        }
    }

    // mac address
    for (unsigned i=0; i<mac_addr.size(); i++) {
        uint8_t u = mac_addr.at(i);

        if (i==0) {
            u ^= 2;
        }

        if (i == 3) {
            oss << "ff:fe";
        }

        oss << std::setfill('0') << std::setw(2) << std::hex << (uint16_t)u;

        if ((i % 2) && (i<5)) {
            oss << ":";
        }
    }

    return oss.str();
};

}
