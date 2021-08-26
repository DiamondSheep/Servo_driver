set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
#project(servo_driver)

# include PCA9685 library
add_subdirectory(JHPWMPCA9685)
list(APPEND EXTRA_LIBS JHPWMPCA9685)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/JHPWMPCA9685")

# include i2c library
list(APPEND EXTRA_LIBS i2c)
list(APPEND EXTRA_INCLUDES "/usr/include/i2c")

#set(sources test.cpp servo_driver.cpp)
#add_executable(servo_driver ${sources})
add_library(servo_driver servo_driver.cpp)

target_link_libraries(servo_driver PUBLIC ${EXTRA_LIBS})
target_include_directories(servo_driver PUBLIC ${EXTRA_INCLUDES})
