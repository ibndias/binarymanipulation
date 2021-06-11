#!/bin/sh

gcc a.c
./a.out $1 $2
echo "In"
hexdump $1 | head
echo "Out"
hexdump $2 | head
#echo "----"
#hexdump $2 | tail