#!/bin/sh

gcc b.c
./b.out $1 > $2
echo "In"
hexdump $1 | head
echo "Out"
cat $2 | head
#echo "----"
#hexdump $2 | tail