mkdir temp>/dev/null 2>/dev/null
g++ $1.cpp -o temp/$1.exe -O2
temp/$1.exe < inputs/$1.in > temp/$1.sol
diff -w -s temp/$1.sol outputs/$1.out