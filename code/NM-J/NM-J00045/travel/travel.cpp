#include <bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    bool f1 = s1 == s2;
    bool f2 = (f1 && c1[0] == c2[0] && c1[1] == c2[1]);
    bool f3 = (f1 && f2 && ((c1[2] <= 'C' && c2[2] <= 'C') || (c1[2] > 'C' && c2[2] > 'C')));
    bool f4 = (f1 && f2 && f3 && ((c1[2] + 1 == c2[2]) || (c1[2] - 1 == c2[2])));
    cout << f1 << f2 << f3 << f4;
    return 0;
}
