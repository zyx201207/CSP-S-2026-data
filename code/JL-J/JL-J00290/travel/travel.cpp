#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 1e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

void solve() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if (s1 == s3) cout << '1';
    else {
        cout << "0000";
        return ;
    }
    if (s2[0] == s4[0] && s2[1] == s4[1]) cout << '1';
    else {
        cout << "000";
        return ;
    }
    int cea, ceb;
    if (s2[2] >= 'A' && s2[2] <= 'C') cea = 1;
    else cea = 0;
    if (s4[2] >= 'A' && s4[2] <= 'C') ceb = 1;
    else ceb = 0;
    if (cea == ceb) cout << '1';
    else {
        cout << "00";
        return ;
    }
    if (s2[2] + 1 == s4[2] || s2[2] - 1 == s4[2]) {
        cout << "1";
    } else {
        cout << 0;
    }
    return ;
}

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}