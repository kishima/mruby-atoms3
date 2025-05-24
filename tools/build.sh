#!/bin/bash 


docker run --rm -v $PWD/../src:/project -w /project espressif/idf:v5.1.4 idf.py build
