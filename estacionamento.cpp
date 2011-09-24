#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int S[10000];
int E[10000];
bool T[100001];

int main() {
    int c, n, comp;
    int placa;
    char tipo;
    while(cin >> c >> n) {
        int total = 0;
        memset(S, 0, sizeof(S));
        memset(E, 0, sizeof(E));
        memset(T, 0, sizeof(T));
        for(int i=0;i<n;i++) {
            cin >> tipo >> placa;
            if (tipo == 'C') {
                cin >> comp;
                for(int j=0;j<c && j+comp<=c;j++) {
                    bool ok = true;
                    for(int k=0;k<comp;k++)
                        if(T[j+k]) ok = false;
                    if (!ok) continue;

                    S[placa] = j;
                    E[placa] = j+comp;
                    for(int k=0;k<comp;k++) {
                        T[j+k] = true;
                    }
                    total += 10;
                    break;
                }
            } else {
                for(int j=S[placa]; j<E[placa]; j++) {
                    T[j] = false;
                }
                S[placa] = 0;
                E[placa] = 0;
            }
        }
        cout << total << endl;
    }
}
