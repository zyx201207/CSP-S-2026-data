#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 5e5 + 10;
int dis[N][N], c, n, m, d, q, w[M], len[M];
struct node {int id, w;};
node e[M][21];
void cmin(int &x, int y) {x = min(x, y);}
int get(int u, int v) {
	if(u > v) swap(u, v);
	return dis[u][v];
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = 1e18;
    }
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1, l; i <= n; i++) {
        scanf("%lld", &l);
        for(int j = 1, x, y; j <= l; j++) {
            scanf("%lld%lld", &x, &y);
            e[x][++len[x]] = {i, y};
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= len[i]; j++) for(int k = j + 1; k <= len[i]; k++) {
            node u = e[i][j], v = e[i][k];
            if(u.id > v.id) swap(u, v);
            cmin(dis[u.id][v.id], u.w + v.w);
        }
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) {
    	cmin(dis[i][j], get(i, k) + get(k, j));
	}
    while(q--) {
        int x, y, ans = 1e18;
        scanf("%lld%lld", &x, &y);
        for(int i = 1; i <= len[x]; i++) for(int j = 1; j <= len[y]; j++) {
            node u = e[x][i], v = e[y][j];
            if(u.id > v.id) swap(u, v);
            cmin(ans, dis[u.id][v.id] + u.w + v.w);
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
}
