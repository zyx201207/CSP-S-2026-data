#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    // freopen("travel5.in", "r", stdin);
    // freopen("travel5.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    char k1 = s1[2], k2 = s2[2];
    if(k1 > k2) swap(k1, k2);
    if((k1 == 'A' && (k2 == 'B' || k2 == 'C')) || (k1 == 'D' && k2 == 'E') || (k1 == 'B' && k2 == 'C')) cout << 1;
    else {
        cout << "00";
        return 0;
    }
    if((int)(k2 - k1) == 1 && k1 != 'C') cout << 1;
    else cout << 0;
    return 0;
}