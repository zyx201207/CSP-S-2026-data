#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool samecx, samep, samec, xl;
    samecx = (c1 == c2);
    samep = (samecx && s1[0] == s2[0] && s1[1] == s2[1]);
    samec = (samep && ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] < 'D' && s2[2] < 'D')));
    xl = (samec && (abs(s1[2] - s2[2]) == 1));
    cout << samecx << samep << samec << xl;
    return 0;
}
