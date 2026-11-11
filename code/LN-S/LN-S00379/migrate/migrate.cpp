#include <bits/stdc++.h>
using namespace std;

int c, t, n, d, ans[2000005], atop = 0;
long long x[2000005];
bool b[2000005];

void dfs(int u, int stp, int v) {
    if (u == v) {
        ans[++atop] = stp;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i != u && !b[i] && abs(x[i] - x[u]) <= d) {
            b[i] = true;
            //printf("%d -> %d\n", u, i);
            fflush(stdout);
            dfs(i, stp + 1, v);
            b[i] = false;
        }
    }
}

bool check(int u, int v) {
    //printf("u=%d,v=%d\n", u, v);
    for (int i = 1; i <= n; i++)
        b[i] = 0;
    atop = 0;
    dfs(u, 0, v);
    sort(ans + 1, ans + 1 + atop);
    //printf("atop=%d\nans=", atop);
    //for (int i = 1; i <= atop; i++)
    //    printf("%d ", ans[i]);
    //printf("\n");
    return (atop >= 2 && ans[1] == ans[2] && ans[2] != ans[3]);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);

            int res = 0;
            for (int u = 1; u <= n; u++)
                for (int v = u + 1; v <= n; v++)
                    if (check(u, v)) {
                        ++res;
                    }
            printf("%d\n", res);

    }
    return 0;
}
