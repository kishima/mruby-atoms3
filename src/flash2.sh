#!/bin/bash

IDF_VER=v5.1.4
HOST_USBDEV=/dev/ttyACM0
TARGET_PROJECT=./

cmd="/opt/esp/python_env/idf5.1_py3.8_env/bin/python ../opt/esp/idf/components/esptool_py/esptool/esptool.py -p /dev/ttyACM0 -b 460800 --before default_reset --after hard_reset --chip esp32s3  write_flash --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0xd000 build/ota_data_initial.bin 0x10000 build/esp32s3.bin"
docker run --rm --device=$HOST_USBDEV:/dev/ttyACM0 -v $PWD/$TARGET_PROJECT:/project -w /project -e HOME=/tmp --entrypoint="" espressif/idf:$IDF_VER bash -c "$cmd"
