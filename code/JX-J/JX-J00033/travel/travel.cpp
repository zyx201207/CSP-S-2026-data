#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string s,t;
    cin >> n >> s >> m >> t;
    int p = s[0] - 48 + s[1] - 48,r = t[0] - 48 + t[1] - 48;
    // cout << p << ' ' << r;
    if (n == m) {
        if (p == r) {
            char c = s[2],ch = t[2];
            if (c == 'A' || c == 'B' || c == 'C') {
                if (ch == 'A' || ch == 'B' || ch == 'C') {
                    if (ch == c + 1 || ch == c - 1) cout << "1111";
                    else cout << "1110";
                }
                else cout << "1100";
            }
            else {
                if (ch == 'D' || ch == 'F') {
                    if (ch == c + 1 || ch == c - 1) cout << "1111";
                    else cout << "1110";
                }
                else cout << "1100";
            }
        }
        else cout << "1000";
    }
    else cout << "0000";
    return 0;
}
