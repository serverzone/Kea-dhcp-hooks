include_directories(../thirdparty/kea/src/lib)

add_library (mac2ipv6 SHARED version.cc load_unload.cc lease6_select.cc logger.cc mac2ip.cc)

install(TARGETS mac2ipv6 LIBRARY DESTINATION /usr/local/lib/kea/hooks)