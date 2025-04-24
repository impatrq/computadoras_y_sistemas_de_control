# Project name
project(lcd)

# Create static library
add_library(lcd STATIC lcd_i2c.c)

# Include header files
target_include_directories(lcd PUBLIC inc)

# Add dependencies
target_link_libraries(lcd PUBLIC pico_stdlib hardware_i2c)
