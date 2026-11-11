#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 505;
const int MAXM = 500010;
const long long lag = 1e18;

struct node {
    int cnt;
    long long w, t[25];
    int tr[25];
};

long long dt[MAXN][MAXN], tt, ans;
node stat[MAXM];
int c, m, n, d, q, k, a, lx, ly, st, ed;

void madecharget(int x) {
    int cntt = stat[x].cnt;
    int lin1, lin2;
    long long t2;
    for (int i=1; i<=cntt; i++) {
        for (int j=i+1; j<=cntt; j++) {
            lin1 = stat[x].tr[i];
            lin2 = stat[x].tr[j];
            t2 = stat[x].t[i] + stat[x].t[j];
            dt[lin1][lin2] = min(dt[lin1][lin2], t2);
            dt[lin2][lin1] = min(dt[lin1][lin2], t2);
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i=1; i<=m; i++) {
        scanf("%lld", &stat[i].w);
        stat[i].cnt = 0;
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &k);
        for (int j=1; j<=k; j++) {
            scanf("%d%lld", &a, &tt);
            stat[a].cnt ++;
            stat[a].tr[stat[a].cnt] = i;
            stat[a].t[stat[a].cnt] = tt;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dt[i][j] = lag;
            if (i==j) dt[i][j] = 0;
        }
    }
    for (int i=1; i<=m; i++) madecharget(i);
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dt[i][j] > dt[i][k] + dt[k][j]) {
                    dt[i][j] = dt[i][k] + dt[k][j];
                }
            }
        }
    }
    while (q--) {
        scanf("%d%d", &st, &ed);
        ans = lag;
        for (int i=1; i<=stat[st].cnt; i++) {
            for (int j=1; j<=stat[ed].cnt; j++) {
                lx = stat[st].tr[i];
                ly = stat[ed].tr[j];
                ans = min(ans, stat[st].t[i] + stat[ed].t[j] + dt[lx][ly]);
            }
        }
        ans += stat[st].w + stat[ed].w;
        printf("%lld\n", ans);
    }
    return 0;
}

