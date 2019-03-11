project (kea_dhcp_hooks_tests)

enable_testing()

find_package(GTest REQUIRED)

include_directories(../src)

add_executable(tests test_main.cc test_mac2ip.cc ../src/mac2ip.cc)

target_link_libraries(tests GTest::GTest GTest::Main)

add_test(AllTests tests)


