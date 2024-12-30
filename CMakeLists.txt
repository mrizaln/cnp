cmake_minimum_required(VERSION 3.12)

project(
  cnp
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "C++20 concepts library")

add_library(cnp INTERFACE)
target_include_directories(cnp INTERFACE include)
target_compile_features(cnp INTERFACE cxx_std_20)
set_target_properties(cnp PROPERTIES CXX_EXTENSIONS OFF)
