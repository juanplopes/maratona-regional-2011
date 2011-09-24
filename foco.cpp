#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int a, b;
    Item(): a(0), b(0) {}
    Item(int a, int b): a(a), b(b){}
};

bool comparee(const Item& a, const Item& b) {
    return a.b < b.b;
}

vector<Item> T;

int main() {
    int n, a, b;
    while(cin >> n) {
        T.clear();
        while(n--) {
            cin >> a >> b;
            T.push_back(Item(a, b));
        }
        sort(T.begin(), T.end(), comparee);
        int maxx = -1;
        int cnt = 0;
        for(int i=0;i<T.size(); i++) {
            if (T[i].a > maxx) {
                //cout << T[i].a << " " << T[i].b << endl;
                cnt++;
                maxx = T[i].b;
            }
        }
        cout << cnt << endl;
   }
}
