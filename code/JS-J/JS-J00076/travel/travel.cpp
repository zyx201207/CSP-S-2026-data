#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
string c1, c2, c3, c4;
string x = "", y = "";
int a, b, c, d;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    IOS;
    cin >> c1 >> c2 >> c3 >> c4;
    if (c1 == c3) {
        a = 1;
        int len1 = c2.size(), len2 = c4.size();
        rep(i, 0, len1 - 2) x += c2[i];
        rep(i, 0, len2 - 2) y += c4[i];
        char t1 = c2[2], t2 = c4[2];
        if (x == y) {
            b = 1;
            if (t1 >= 'D' && t2 >= 'D') c = 1;
            if (t1 <= 'C' && t2 <= 'C') c = 1;
        }
        if (t1 + 1 == t2 || t2 + 1 == t1) {
            if (c == 1) d = 1;
        }
    }
    cout << a << b << c << d << '\n';
    return 0;
}
