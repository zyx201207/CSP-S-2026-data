#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool last = 1;
    cout << (last = (last && c1 == c2));
    cout << (last = (last && s1[0] == s2[0] && s1[1] == s2[1]));
    cout << (last = (last && (!(s1[2] <= 'C') ^ (s2[2] <= 'C'))));
    cout << (last = (last && abs(s1[2] - s2[2]) == 1));
    return 0;
}
