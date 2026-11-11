#include<bits/stdc++.h>
#define ll long long
#define ary array<int, 2>
using namespace std;
const int M = 5e5 + 5, N = 505, D = 21;
const ll inf = 1e18;
int c, n, m, d, q, w[M];
int cnt[M];
int pos[D][M][2];
ll dis[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, len, x; i <= n; i++){
		cin >> len;
		for(int j = 1, w; j <= len; j++){
			cin >> x >> w;
			cnt[x]++;
			pos[cnt[x]][x][0] = i, pos[cnt[x]][x][1] = w;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				dis[i][j] = inf;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= cnt[i]; j++){
			for(int k = j + 1; k <= cnt[i]; k++){
				int u = pos[j][i][0], v = pos[k][i][0];
				ll wu = pos[j][i][1], wv = pos[k][i][1];
				dis[v][u] = dis[u][v] = min(dis[u][v], wu + wv);
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
		ll ans = inf;
		for(int j = 1; j <= cnt[x]; j++){
			for(int k = 1; k <= cnt[y]; k++){//根本不会重复经过，因为那压根就不优! 
				int u = pos[j][x][0], v = pos[k][y][0];
				ll wu = pos[j][x][1], wv = pos[k][y][1];
				ans = min(ans, dis[u][v] + wu + wv + w[x] + w[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
d^2*m + d^2*q + n^3

有个问题是如果最短路要经过x, y咋办，会算重啊 

为什么，就差一点

woc，根本没有这样的情况 

如果会走回x，那么为啥我不直接走另一个方向！ 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

I LOVE floyd

极限了，难道2e8是错的？

算了，反正都这样了 ，至少应该比暴力高 

有可能挂24pts
[76,100] 
*/
