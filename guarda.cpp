#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int TE[70];
int TD[70];

int main() {
    int d, vf, vg;
    while(cin >> d >> vf >> vg) {
        bool consegue = (12.0/vf) >= sqrt(d*d+144)/vg;
        cout << (consegue ? "S" : "N") << endl;

    }
}
