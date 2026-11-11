#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
array<bool, 5> postype = {0, 0, 0, 1, 1};
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    bool q1 = c1 == c2;
    bool q2 = q1 && (s1.substr(0, s1.size() - 1) == s2.substr(0, s2.size() - 1));
    bool q3 = q2 && (postype[s1.back() - 'A'] == postype[s2.back() - 'A']);
    bool q4 = q3 && (abs(s1.back() - s2.back())) == 1;
    cout << q1 << q2 << q3 << q4 << endl;
    return 0;
}