#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

#define File
#define FileName "travel"

void solve();

/*

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifdef File
    freopen(FileName ".in", "r", stdin);
    freopen(FileName ".out", "w", stdout);
#endif
    int T = 1;
    while(T--) solve();
    return 0;
}

void solve() {
    int c1,s1, c2, s2;
    char d1, d2;
    cin >> c1 >> s1 >> d1 >> c2 >> s2 >> d2;
    // cout << c1 << " " << s1 << d1 << "\n" << c2 << " " << s2 << d2;
    if (c1 == c2) {
        cout << "1";
        if (s1 == s2) {
            cout << "1";
            if (!((d1 <= 'C')^(d2 <= 'C'))) {
                cout << "1";
                if (abs(d1 - d2) == 1) {
                     cout << "1";
                } else cout << "0";
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
}
