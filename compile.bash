#!/bin/bash
# Run build compile our project

cd build

cmake ..
cmake --build . --config Debug

cd ..