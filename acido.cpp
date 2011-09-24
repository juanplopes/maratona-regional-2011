#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;

    while(cin >> s) {
        stack<char> Q;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if (!Q.empty() && (
                c == 'B' && Q.top() == 'S' ||
                c == 'S' && Q.top() == 'B' ||
                c == 'F' && Q.top() == 'C' ||
                c == 'C' && Q.top() == 'F')) {
                  Q.pop();
                  cnt++;
            } else {
                Q.push(c);
            }
        }
        cout << cnt << endl;
    }
}
