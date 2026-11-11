#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
int read() {
    int g = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        g = g * 10 + (ch ^ 48);
        ch = getchar();
    }
    return g * f;
}
string c1, s1, c2, s2;
bool same[200];
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    same['A'] = same['B'] = same['C'] = 1;
    cin >> c1 >> s1 >> c2 >> s2;
    if (s1[2] == 'F') s1[2] = 'E';
    if (s2[2] == 'F') s2[2] = 'E';
    if (c1 == c2) putchar('1');
    else putchar('0');
    if (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2)) putchar('1');
    else putchar('0');
    if (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && same[s1[2]] == same[s2[2]]) putchar('1');
    else putchar('0');
    if (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && same[s1[2]] == same[s2[2]] && abs(s1[2] - s2[2]) == 1) putchar('1');
    else putchar('0');
    return 0;
}