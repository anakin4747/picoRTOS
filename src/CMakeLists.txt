add_executable(main
        main.c
)

target_link_libraries(main pico_stdlib FreeRTOS)
pico_add_extra_outputs(main)
