cmake_minimum_required(VERSION 3.15)

project(fx_gltf_consumer LANGUAGES CXX)

find_package(fx-gltf CONFIG REQUIRED)

add_executable(fx_gltf_consumer test_package.cpp)
target_compile_features(fx_gltf_consumer PRIVATE cxx_std_17)
target_link_libraries(fx_gltf_consumer PRIVATE fx-gltf::fx-gltf)
