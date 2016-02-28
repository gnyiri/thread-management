cmake_minimum_required(VERSION 2.8.1)

project(example)

set(example-sources
  main.cxx 
)

add_executable(example ${example-sources})

target_link_libraries(example producer_consumer pthread)