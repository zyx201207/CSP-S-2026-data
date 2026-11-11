#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e6 + 5;
int n, m, ans, idx, f[31], a[200005], s[N], nxt[N][2];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 30; j >= 0; --j)
            if ((a[i] >> j) & 1)
                ++f[j];
    }
    int p = 0;
    for (int i = 30; i >= 0; --i)
        if (f[i] >= m) {
            p = i;
            break;
        }
    for (int i = 1; i <= n; i++)
        if ((a[i] >> p) & 1) {
            int now = 0;
            for (int j = p - 1; j >= 0; --j) {
                int x = (a[i] >> j) & 1;
                if (!nxt[now][x])
                    nxt[now][x] = ++idx;
                now = nxt[now][x];
                ++s[now];
            }
        }
    int now = 0;
    for (int i = p - 1; i >= 0; --i) {
        if (s[nxt[now][1]] >= m)
            now = nxt[now][1], ans += (1 << i);
        else
            now = nxt[now][0];
    }
    printf("%d\n", ans + (1 << p));
}

