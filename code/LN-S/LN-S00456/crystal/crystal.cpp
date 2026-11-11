#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define make_pair m_p
using namespace std;
ll read() {
    ll w = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') {
            f = -f;
        }
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        w = w * 10 + c - '0';
        c = getchar();
    }
    return w * f;
}
void write(ll x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
const int N = 5e5 + 5;
ll n, m, ans, a[N], sum[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    rep(i, 1, n) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        sum[i] = sum[i - 1] + a[i];
    }
    rep(i, 1, n) {
        ll L = 0, R = i + 1;
        while(R - L > 1) {
            ll mid = (L + R) >> 1;
            if(mid * a[i] - (sum[i] - sum[i - mid]) <= m) {
                L = mid;
            } else {
                R = mid;
            }
        }
        ans = max(ans, L);
    }
    write(ans);
    return 0;
}   