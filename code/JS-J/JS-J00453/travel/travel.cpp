#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    int cx1 = (c1[0] - '0') * 10 + c1[1] - '0';
    int cx2 = (c2[0] - '0') * 10 + c2[1] - '0';
    int pa1 = (s1[0] - '0') * 10 + s1[1] - '0';
    int pa2 = (s2[0] - '0') * 10 + s2[1] - '0';
    char zw1 = s1[2];
    char zw2 = s2[2];
    int ce1 = (zw1 <= 'C');
    int ce2 = (zw2 <= 'C');
    if (cx1 == cx2) cout << 1;
    else cout << 0;
    if (cx1 == cx2 && pa1 == pa2) cout << 1;
    else cout << 0;
    if (cx1 == cx2 && pa1 == pa2 && ce1 == ce2) cout << 1;
    else cout << 0;
    if (cx1 == cx2 && pa1 == pa2 && ce1 == ce2 && (abs(zw1 - zw2) == 1 || (zw1 == 'D' && zw2 == 'F') || (zw2 == 'D' && zw1 == 'F'))) cout << 1;
    else cout << 0;
    return 0;
}
