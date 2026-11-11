#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int TaskId;
int n, m, d, q;
ll w[500010];
ll num[500010][21][2];
ll len[500010];
ll dist[510][510];

int main (){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d", &TaskId);
    scanf("%d%d%d%d", &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        int l;
        scanf("%d", &l);
        for (int j = 1; j <= l; j++) {
            int a, t;
            scanf("%d%d", &a, &t);
            num[a][len[a]][0] = i;
            num[a][len[a]][1] = t;
            len[a]++;
        }
    }
    memset(dist, 127, sizeof(dist));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 1; i <= m; i++) if (len[i] >= 2) {
        int sz = len[i];
        for (int j = 0; j < sz; j++) {
            for (int k = j + 1; k < sz; k++) {
                int num1 = num[i][j][0], num2 = num[i][k][0];
                ll t1 = num[i][j][1], t2 = num[i][k][1];
                dist[num1][num2] = min(dist[num1][num2], t1 + t2);
                dist[num2][num1] = min(dist[num2][num1], t1 + t2);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < (1LL << 60LL) && dist[k][j] < (1LL << 60LL))
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int szu = len[u];
        int szv = len[v];
        ll mi = 1LL << 60LL;
        for (int i = 0; i < szu; i++) {
            for (int j = 0; j < szv; j++) {
                int num1 = num[u][i][0], num2 = num[v][j][0];
                ll t1 = num[u][i][1], t2 = num[v][j][1];
                mi = min(mi, dist[num1][num2] + t1 + t2);
            }
        }
        printf("%lld\n", mi + w[u] + w[v]);
    }
}
