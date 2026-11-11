#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1, c2;
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char s1, s2, s3, s4, s5, s6;
    cin >> c1 >> s1 >> s2 >> s3 >> c2 >> s4 >> s5 >> s6;
    if(c1 != c2) {
        cout << "0000";
    }
    else {
        if(s1 == s4 && s2 == s5) {
            int o = s3 - 'A';
            int p = s6 - 'A';
            if((o > 2 && p > 2) || (o <= 2 && p <= 2)) {
                if(abs(o - p) == 1) cout << 1111;
                else cout << 1110;
            }
            else {
                cout << 1100;
            }
        }
        else {
            cout << 1000;
        }
    }
    return 0;
}
