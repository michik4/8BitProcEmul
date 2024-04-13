cmake_minimum_required(VERSION 2.8.12)
project(C8BitProcEmul C)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)

include_directories(
    "include"
)
add_definitions(
    -DDEBUG
    -std=c11
)

set(SRC_LIST 
    main.c
    comp/ALU.c
    dbm/bit.c
)



add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
