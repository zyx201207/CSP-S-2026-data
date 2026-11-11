#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool ans[4];
    ans[0] = (c1 == c2);
    ans[1] = (s1.substr(0, 2) == s2.substr(0, 2)) && ans[0];
    ans[2] = (('A' <= s1[2] <= 'C' && 'A' <= s2[2] <= 'C') || ('D' <= s1[2] <= 'E' && 'D' <= s2[2] <= 'E')) && ans[1] && min(s1[2], s2[2]) != 'C';
    ans[3] = ((s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1)) && ans[2];
    for (bool i : ans) putchar(i + '0');
    return 0;
}