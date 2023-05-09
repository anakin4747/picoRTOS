set(PICO blink)

add_executable(${PICO}
    main.c
)

target_link_libraries(${PICO} 
    pico_stdlib 
    freertos
)
pico_add_extra_outputs(${PICO})

add_custom_target(flash
    DEPENDS ${PICO}.uf2
    COMMAND cp ${PICO}.uf2 /media/kin/RPI-RP2/
)
