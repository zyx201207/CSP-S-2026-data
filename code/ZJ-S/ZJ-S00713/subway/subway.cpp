#include <bits/stdc++.h>
#define ll long long
using namespace std;
int id, n, m, d, q;
ll w[500005];
int k[505], cnt[500005];
struct node{
	int pos;//line number
	ll t;//time
}p[500005][25];
ll dis[505][505];//dis[i][j]=mintime(line i->line j)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> id >> n >> m >> d >> q;
	for (int i=1; i <= m; ++i)  cin >> w[i];
	for (int i=1; i <= n; ++i){
		cin >> k[i];
		for (int j=1, a; j <= k[i]; ++j){
			ll t;
			cin >> a >> t;
			p[a][++cnt[a]] = node{i, t};
		}
		for (int j=1; j <= n; ++j)  dis[i][j] = 1e18;
	}
	for (int i=1; i <= m; ++i){
		if (cnt[i] <= 1)  continue;
		for (int j=1; j < cnt[i]; ++j){
			for (int k=j+1; k <= cnt[i]; ++k){
				if (dis[p[i][j].pos][p[i][k].pos] > p[i][j].t+p[i][k].t){
					dis[p[i][j].pos][p[i][k].pos] = dis[p[i][k].pos][p[i][j].pos] = p[i][j].t+p[i][k].t;
				}
			}
		}
	}//build edge
	for (int k=1; k <= n; ++k){
		for (int i=1; i <= n; ++i){
			for (int j=1; j <= n; ++j){
				if (i != j && j != k && k != i)  dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]); 
			}
		}
		dis[k][k] = 0;
	}//floyd
	while (q--){
		int x, y;
		ll ans = 1e18;
		cin >> x >> y;
		for (int i=1; i <= cnt[x]; ++i){
			for (int j=1; j <= cnt[y]; ++j){
				ans = min(ans, dis[p[x][i].pos][p[y][j].pos]+p[x][i].t+p[y][j].t);
			}
		}
		cout << ans+w[x]+w[y] << "\n";
	}
	return 0;
}
