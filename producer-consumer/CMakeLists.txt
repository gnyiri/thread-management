cmake_minimum_required(VERSION 2.8.1)

project(producer-consumer)

set(producer-consumer-sources
  ../common/thread-manager.cxx
  producer-consumer.cxx
)

add_library(producer_consumer SHARED ${producer-consumer-sources})

target_link_libraries(producer_consumer pthread)
