#!/bin/bash
export PROJECT_NAME="pico-project-template"
export ELF_LOAD_FILE=$PROJECT_NAME".elf"
export PICO_SDK_PATH="/home/seth/pico/pico-sdk"
export PICO_PROJECT_PATH="/home/seth/pico-development/"$PROJECT_NAME
export PICO_PROJECT_BUILD=$PICO_PROJECT_PATH"/build/src/"
export PICO_LIBRARY_PATH="/home/seth/pico-development/pico-libraries"

cmake $PICO_PROJECT_PATH/CMakeLists.txt -B $PICO_PROJECT_PATH/build
echo ==========================================================================
make -C $PICO_PROJECT_BUILD
echo ==========================================================================
openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program $PICO_PROJECT_BUILD${ELF_LOAD_FILE} verify reset exit"
