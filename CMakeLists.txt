cmake_minimum_required(VERSION 3.27)
project(insuline_pump)

set(CMAKE_CXX_STANDARD 14)

include_directories(con2db)
include_directories(con2redis/src)
include_directories(con2redis/src/old)
include_directories(src)

add_executable(insuline_pump
        con2db/pgsql.cpp
        con2db/pgsql.h
        con2redis/src/old/con2redis.h
        con2redis/src/old/readreply.cpp
        con2redis/src/con2redis.h
        con2redis/src/local.h
        con2redis/src/readreply.cpp
        con2redis/src/redisfun.cpp
        src/Paziente.cpp
        src/Paziente.h)
