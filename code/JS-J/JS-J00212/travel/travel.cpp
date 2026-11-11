#include <bits/stdc++.h>
using namespace std;
#define int long long

string c1, s1, c2, s2;

signed main () {
    ios :: sync_with_stdio (0); cin.tie(0); cout.tie(0);
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    if (s1.at(0) == s2.at(0) && s1.at(1) == s2.at(1)) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    if ( ( (s1.at(2) == 'A' || s1.at(2) == 'B' || s1.at(2) == 'C')
        && (s2.at(2) == 'A' || s2.at(2) == 'B' || s2.at(2) == 'C'))
        || ( (s1.at(2) == 'D' || s1.at(2) == 'F')
        && ( (s1.at(2) == 'D' || s1.at(2) == 'F') ))  ) {

        cout << 1;
    }
    else {
        cout << "00";
        return 0;
    }
    if ( (s1.at(2) == 'A' && s2.at(2) == 'B') || (s1.at(2) == 'B' && s2.at(2) == 'C') || (s1.at(2) == 'D' && s2.at(2) == 'F')
        || (s2.at(2) == 'A' && s1.at(2) == 'B') || (s2.at(2) == 'B' && s1.at(2) == 'C') || (s2.at(2) == 'D' && s1.at(2) == 'F') ) {
        cout << 1;
    }
    else cout << 0;
    return 0;
}
