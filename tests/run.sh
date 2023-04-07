#!/bin/bash
input="./testinput"
while IFS= read -r line
do
  ../computor "$line"
done < "$input"