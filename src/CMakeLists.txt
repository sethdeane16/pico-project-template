add_executable($ENV{PROJECT_NAME}
	main.c
)

include_directories(
    $ENV{PICO_PROJECT_PATH}/include
    $ENV{PICO_LIBRARY_PATH}/library-template/library-template/
)

target_link_libraries($ENV{PROJECT_NAME}
	pico_stdlib
    library-template
)
