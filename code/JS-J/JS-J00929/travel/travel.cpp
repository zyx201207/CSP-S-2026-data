#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, s, d, f;
    cin >> a >> s >> d >> f;
    bool ansa = (a == d);
    bool anss = (ansa && s[0] == f[0] && s[1] == f[1]);
    bool ansd = ((ansa && anss) && ((s[2] < 'D' && f[2] < 'D') || (s[2] > 'C' && f[2] > 'C')));
    bool ansf = ((ansa && anss && ansd) && (abs(s[2] - f[2]) == 1 || (s[2] == 'D' && f[2] == 'F') || (f[2] = 'D' && s[2] == 'F')));
    cout << ansa << anss << ansd << ansf << "\n";
    return 0;
}