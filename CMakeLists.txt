# Copyright 2015 by Martin Moene
#
# gsl-lite is based on GSL: Guideline Support Library,
# https://github.com/microsoft/gsl
#
# This code is licensed under the MIT License (MIT). 

cmake_minimum_required( VERSION 2.8 )

project( gsl_lite )

add_library(    gsl_lite INTERFACE )
target_sources( gsl_lite INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/gsl-lite.natvis )

enable_testing()

add_subdirectory( test )
#add_subdirectory( example )

# end of file
