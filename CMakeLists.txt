cmake_minimum_required(VERSION 3.10)
project(Calculate-Pi)

add_executable(Calculate-Pi
    src/main.cpp
    src/formulas/chudnovsky.cpp
    src/formulas/euler.cpp
    src/formulas/leibniz.cpp
    src/formulas/ramanujan.cpp
    src/formulas/wallis.cpp
)

target_include_directories(Calculate-Pi PRIVATE
    include
)

target_link_libraries(Calculate-Pi
    mpfr
    gmp
)

target_compile_options(Calculate-Pi PRIVATE)