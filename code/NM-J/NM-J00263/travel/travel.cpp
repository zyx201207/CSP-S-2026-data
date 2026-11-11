#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int r1, r2;
char l1, l2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    // cout << c1 << ' ' << s1 << ' ' << c2 << ' ' << s2 << endl;

    r1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    r2 = (s2[0] - '0') * 10 + (s2[1] - '0');

    l1 = s1[2];
    l2 = s2[2];

    // cout << r1 << ' ' << r2 << ' ' << l1 << ' ' << l2 << endl;

    if (c1 == c2) cout << 1;
    else cout << 0;

    if (c1 == c2 && r1 == r2) cout << 1;
    else cout << 0;

    if (c1 == c2 && r1 == r2 && !((l1 <= 'C' && l2 >= 'D') || (l1 >= 'D' && l2 <= 'C'))) cout << 1;
    else cout << 0;

    if (c1 == c2 && r1 == r2 && !((l1 <= 'C' && l2 >= 'D') || (l1 >= 'D' && l2 <= 'C')) && ((abs(l1 - l2) == 1) || (l1 == 'F' && l2 == 'D') || (l1 == 'D' && l2 == 'F'))) cout << 1;
    else cout << 0;

    return 0;
}
