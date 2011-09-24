#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int TE[70];
int TD[70];

int main() {
    int n, tam;
    char e;
    while(cin >> n) {
        memset(TE, 0, sizeof(TE));
        memset(TD, 0, sizeof(TD));
        for(int i=0;i<n;i++) {
            cin >> tam >> e;
            if (e=='E')
                TE[tam]++;
            if (e=='D')
                TD[tam]++;
        }

        int soma = 0;
        for(int i=0; i<70; i++) {
            soma += min(TE[i], TD[i]);
        }
        cout << soma << endl;
    }
}
