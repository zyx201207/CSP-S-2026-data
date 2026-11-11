#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
string c1, s1, c2, s2;
int side(char c) {
    if (c <= 'C') return 0;
    else return 1;
}
void check(bool f) {
    if (f) cout << 1;
    else cout << 0;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    check(c1 == c2);
    check(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]));
    check(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && side(s1[2]) == side(s2[2]));
    check(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && side(s1[2]) == side(s2[2]) && abs(s1[2] - s2[2]) == 1);
    cout << endl;
    return 0;
}
// 100
