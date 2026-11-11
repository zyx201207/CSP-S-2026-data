#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int near(char a, char b) {
    int fa = 0, fb = 0;
    if (a - 'A' < 3) fa = 0;
    else fa = 1;
    if (b - 'A' < 3) fb = 0;
    else fb = 1;
    if (fa != fb) return 0;
    if (a == 'B' || b == 'B') {
        if (a == 'A' || b == 'A' || a == 'C' || b == 'C') return 2;
        return 1;
    }
    if (a == 'D' || b == 'D') {
        if (a == 'F' || b == 'F') return 2;
        return 1;
    }
    return 1;
} /*0row 1near 2ok*/

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int flag = near(s1[2], s2[2]);
    if (c1 != c2) cout << "0000";
    else if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
    else if (flag == 0) cout << "1100";
    else if (flag == 1) cout << "1110";
    else cout << "1111";
    return 0;
}
