#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int LOG = 40;
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
int n, m, a[N], cnt[LOG];
vector<int> b[LOG], c;
int bit(int x) {
    int res = 0;
    while (x) {
        x >>= 1;
        res++;
    }
    return res;
}
bool cmp(int x, int y) {
    return x > y;
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1, cmp);
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << bit(31) << endl;
    for (int i = 1; i <= n; i++) b[bit(a[i])].pb(a[i]);
    // for (int i = 0; i <= bit(a[1]); i++) {
    //     for (int j : b[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }    
    for (int i = 1; i <= n; i++) {
        int tmp = a[i], now = 1;
        while (tmp) {
            if (tmp % 2) cnt[now]++;
            now++;
            tmp >>= 1;
        }
    }
    int now;
    for (now = bit(a[1]); now >= 1; now--) {
        if (cnt[now] >= m) break;
    }
    if (!now) {
        printf("0\n");
        exit(0);
    }
    // cout << now << endl;
    for (int i = bit(a[1]); i >= now; i--) {
        int diff = 0;
        for (int j = i - 1; j >= now; j--) {
            diff += (1ll << j);
        }
        for (int j : b[i]) {
            c.pb(j - diff);
        }
    }
    sort(c.begin(), c.end(), cmp);
    // for (int i : c) {
    //     printf("%lld ", i);
    // }
    // putchar('\n');
    int ans = c[0];
    for (int i = 0; i < m; i++) ans &= c[i];
    printf("%lld\n", ans);
    return 0;
}