#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e6 + 10;
int c, t, n;
long long d, a[maxn];
inline long long read() {
    long long res = 0, f = 1; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') f = -1, c = getchar();
    while (isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return f * res;
}
int dp[maxn], nxt[maxn], w[maxn];
int dp2[maxn], pre[maxn], w2[maxn];
long long t1[maxn], t2[maxn];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while (t--) {
        n = read(), d = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        int lst = n, lst2 = n;
        for (int i = n; i >= 1; i--) {
            while (a[lst] - a[i] > d) lst--;
            nxt[i] = lst;
            if (i == lst) {
                w[i] = 0, dp[i] = 1; continue;
            }
            if (a[nxt[lst]] - a[lst - 1] <= d) {
                w[i] = 1; dp[i] = lst - i + 1;
                continue;
            }
            w[i] = w[lst] + 1;
            while (a[lst2] - a[lst - 1] > d) lst2--;
            w[i] += max(0, nxt[lst] - lst2 - 1);
            dp[i] = w[i] + (lst - i);
        }
        //for (int i = n; i >= 1; i--) cout << i << ' ' << nxt[i] << ' ' << w[i] << '\n';
        lst = 1, lst2 = 1;
        for (int i = 1; i <= n; i++) {
            while (a[i] - a[lst] > d) lst++;
            pre[i] = lst;
            if (i == lst) {
                w2[i] = 0, dp2[i] = 1; continue;
            }
            if (a[lst + 1] - a[pre[lst]] <= d) {
                w2[i] = 1; dp2[i] = i - lst + 1;
                continue;
            }
            w2[i] = w2[lst] + 1;
            while (a[lst + 1] - a[lst2] > d) lst2++;
            w2[i] += max(0, lst2 - pre[lst] - 1);
            dp2[i] = w2[i] + (i - lst);
        }
        //for (int i = 1; i <= n; i++) cout << i << ' ' << pre[i] << ' ' << w2[i] << '\n';
        lst = n;
        for (int i = n; i >= 1; i--) {
            if (pre[i] != i && pre[i] != i - 1 && nxt[pre[i]] == i) {
                if (a[nxt[i]] - a[i - 1] <= d) t1[pre[i]] += 1;
                else {
                    while (a[lst] - a[i - 1] > d) lst--;
                    t1[pre[i]] += w[i] + max(0, nxt[i] - lst - 1);
                }
            }
        }
        lst = 1;
        for (int i = 1; i <= n; i++) {
            if (nxt[i] != i && nxt[i] != i + 1 && pre[nxt[i]] == i) {
                if (a[i + 1] - a[pre[i]] <= d) t2[nxt[i]] += 1;
                else {
                    while (a[i + 1] - a[lst] > d) lst++;
                    t2[nxt[i]] += w2[i] + max(0, lst - pre[i] - 1);
                }
            }
        }
        long long ans = 0;
        //for (int i = 1; i <= n; i++) cout << t1[i] << ' ' << t2[i] << '\n';
        for (int i = 1; i < n; i++) {
            ans += 1ll * t1[i] * t2[i + 1];
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) t1[i] = t2[i] = 0;
    }
    return 0;
}
