#include <bits/stdc++.h>
using namespace std;
#define int long long
#define get getchar
inline int read() {
    int x = 0, f = 1;
    char ch = get();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -f;
        ch = get();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - 48);
        ch = get();
    }
    return x * f;
}
int n, m, a[200005], ans = -1e9;
void asd(int p, int x, int cnt) {
    if(x == m) {
        ans = max(ans, cnt);
        return ;
    }
    if(p > n || cnt == 0) return ;
    if(n - p + 1 + x < m) return ;
    asd(p + 1, x + 1, cnt & a[p]);
    asd(p + 1, x, cnt);
}
int tt[35];
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    tt[0] = 1;
    for(int i = 1; i <= 30; i++) {
        tt[i] = tt[i-1] * 2;
    }
    n = read();
    m = read();
    bool f = 1;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(f) {
                bool ff = 0;
            for(int i = 0; i <= 30; i++) {
                if(a[i] + 1 == tt[i]) {
                    ff = 1;
                    break;
                }
            }
        f = ff;
        }
    }
    if(f) {
        sort(a + 1, a + n + 1);
        cout << a[n-m+1];
        return 0;
    }
    int st = pow(2, 30) - 1;
    asd(1, 0, st);
    cout << ans;
    return 0;
}
