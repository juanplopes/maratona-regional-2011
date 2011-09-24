#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int M[100010];

int main() {
    int n, m, a, b;
    char op;
    while(cin >> n >> m) {
        memset(M, 0, sizeof(M));

        while(m--) {
            cin >> op >> a >> b;

            if (op == 'M') {
                for(int i=a; i<=b; i++) {
                    M[i]++;
                    if (M[i] == 3) M[i]=0;
                }
            } else {
                int C[3]= {0, 0, 0};
                for(int i=a; i<=b; i++) {
                    C[M[i]]++;
                }
                cout << C[0] << " " << C[1] << " " << C[2] << endl;
            }
        }
        cout << endl;

    }
}
