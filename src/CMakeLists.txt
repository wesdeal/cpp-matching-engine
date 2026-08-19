# core library: the headers in include/ plus their out-of-line definitions.
# main.cpp deliberately stays out of it - a library holding main() cannot be
# linked into a test binary that brings its own main.
add_library(
    me_core
    types.cpp
)

# PUBLIC: used to compile me_core AND propagated to anything linking it,
# so unit_tests gets include/ for free.
target_include_directories(
    me_core
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(
    matching_engine
    main.cpp
)

target_link_libraries(
    matching_engine
    PRIVATE me_core
)
