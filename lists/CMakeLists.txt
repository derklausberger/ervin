include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_library(lists STATIC ${SOURCES})
