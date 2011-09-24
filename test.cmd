@echo off
mkdir temp>NUL 2>NUL
g++ %1.cpp -o temp\%1.exe -O2
temp\%1.exe < inputs\%1.in > temp\%1.sol
fc temp\%1.sol outputs\%1.out