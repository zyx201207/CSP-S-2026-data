#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define getchar getchar_unlocked

void r(int &x) {
    bool flag = 0; int res = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') flag = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    x = (flag?-res:res);
}
int c;
const int N = 2e6+5;
int x[N];
int n, d; 

void solve() {
    r(n), r(d);
    for (int i = 1; i <= n; i++) r(x[i]);
    int delta = abs(x[2]-x[1]);
    if (2 * delta <= d && 3 * delta < d) {
        cout << n-3 << endl;
    }else cout << 0 << endl;

}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    r(c); int t; r(t);
    while (t--) solve();
    return 0;
}