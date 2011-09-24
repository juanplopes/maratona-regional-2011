#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

bool V[MAX];
int O[MAX], npv, CO[MAX], G2[MAX][MAX];
bool G[MAX][MAX];
int n, m;

void DFS(int v){
    V[v] = true;
    for(int i = 0; i < n; i++)
        if (G[v][i] && !V[i])
            DFS(i);
    O[npv++] = v;
}

void DFSt(int v, int comp){
    V[v] = true;   CO[v] = comp;
    for(int i = 0; i < n; i++)
       if (G[i][v] && !V[i])
            DFSt(i,comp);
}

int gPre[MAX], gLow[MAX], gpe, cp1, cp2, comp;
void Pontes(int u,int v) {
    gPre[v] = gLow[v] = gpe++;
    for(int w = 0; w < comp; w++) {
        if(G2[w][v] > 0 && w != v)                   {
            //cout << "OHAI" << w << " " << v << " " << G2[w][v] << endl;
            if(gPre[w] < 0){
                Pontes(v,w);
                if(gLow[w] < gLow[v]) gLow[v] = gLow[w];
                if(gLow[w] == gPre[w]) if (G2[v][w] == 1) cp1++; else cp2++;
            }
            else if( (w != u) && (gPre[w] < gLow[v])) gLow[v] = gPre[w];
        }
    }
}

int main() {
    int a, b, t;
    while(cin >> n >> m) {
        memset(G, 0, sizeof(G));
        memset(G2, 0, sizeof(G2));
        cin >> a >> b >> t; m--;
        
        while(m--) {
            cin >> a >> b >> t;
            a--; b--;
            G[a][b] = true;
            if (t==2)
                G[b][a] = true;
        }
        
        npv = 0;
        memset(V, 0, sizeof(V));
        memset(O, 0, sizeof(O));
        memset(CO, 0, sizeof(CO));

        for(int i = 0; i < n; i++)
            if(!V[i]) DFS(i);


        memset(V, 0, sizeof(V));

        comp = 0;
        for(int i = n-1; i >= 0; i--)
            if(!V[O[i]]) DFSt(O[i], comp++);

        if (comp == 1) {
            cout << "-" << endl;
            continue;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (G[i][j]) {
                    G2[CO[i]][CO[j]]++;
                    G2[CO[j]][CO[i]]++;
                }
            }
        }
        
        memset(gPre, 0xFF, sizeof(gPre));
        memset(gLow, 0xFF, sizeof(gLow));
        gpe = cp2 = cp1 = 0;
        Pontes(0,0);

        if (gpe < comp) {
            cout << "*" << endl;
        } else if (cp1 > 0) {
            cout << "2" << endl;
        } else {
            cout << "1" << endl;
        }
    }

    return 0;
}
