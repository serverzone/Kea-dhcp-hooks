#include <boost/foreach.hpp>
#include <hooks/hooks.h>
#include "hook.h"

using namespace isc::hooks;
using namespace isc::data;

extern "C" {

isc::dhcp::ClientClasses hook_mac2ipv6_client_classes;

int load(LibraryHandle& handle)
{
    // parse client-classes configuration
    ConstElementPtr client_classes = handle.getParameter("client-classes");
    if (client_classes)
    {
        if (client_classes->getType() != Element::list)
        {
            return (101); // incorrect parametr type
        }

        BOOST_FOREACH(ConstElementPtr el, client_classes->listValue())
        {
            if (el->getType() != Element::string)
            {
                return (102); // incorrect list parameter type
            }

            hook_mac2ipv6_client_classes.insert(el->stringValue());
        }
    }

    return (0);
}

int unload()
{
    return (0);
}

}