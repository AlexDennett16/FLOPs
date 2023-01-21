#!/bin/sh

echo "This is a script that iterates over an N Squared List to find machine FLOPs"

g++ q1.cpp -o q1

./q1 $1 $2 

exit 0
