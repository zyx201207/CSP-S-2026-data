#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int f(int x) { return (x <= 2); }
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    int t1 = b[2] - 'A', t2 = d[2] - 'A';
    if(t1 == 5) t1--;
    if(t2 == 5) t2--;
    if(a == c) {
        cout << "1";
        if(b.substr(0, 2) == d.substr(0, 2)) {
            cout << "1";
            if(f(t1) == f(t2)) {
                cout << "1";
                if(abs(t1 - t2) == 1) cout << "1";
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
