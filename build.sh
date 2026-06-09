#!/bin/bash

mkdir -p build

echo "Building Packet Analyzer..."

gcc src/*.c -Iinclude -o build/packet_analyzer

if [ $? -eq 0 ]
then 
    echo "Build successful"
else
    echo "Build failed"
fi