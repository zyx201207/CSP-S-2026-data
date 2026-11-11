#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5005;

int c, t, n, minv, cnt, ans;
LL d, x[N];
int pos[N];

void dfs(int u, int v, int t) {
    if (u == v) {
        pos[t + 1] = v;
        for (int i = 2; i <= t + 1; i++)
            if (x[pos[i]] - x[pos[i - 1]] > d)
                return ;

        if (t == minv) cnt++;
        if (t < minv) minv = t, cnt = 1;
        return ;
    }

    for (int i = u + 1; i <= v; i++) {
        pos[t + 1] = i;
        dfs(i, v, t + 1);
        pos[t + 1] = 0;
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    scanf("%d%d", &c, &t);

    while (t--) {
        ans = 0;
        memset(x, 0, sizeof x);

        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cnt = 0, minv = 1e9;
                pos[1] = i;
                dfs(i, j, 1);
                if (cnt == 2) ans++;
            }
        }

        printf("%d", ans);
    }

    return 0;
}

