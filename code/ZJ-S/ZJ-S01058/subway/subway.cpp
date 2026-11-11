#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N = 5e5 + 10;
const int M = 510;
const ll INF = 1e18;
int c, n, m, d, q, ww[N];
ll dis[M][M];
vector<pr> v[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i){
		cin >> ww[i];
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			dis[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;++i) dis[i][i] = 0;
	for(int i = 1;i <= n;++i){
		int k;
		cin >> k;
		for(int j = 1;j <= k;++j){
			int x, y;
			cin >> x >> y;
			v[x].emplace_back(make_pair(i, y));
		}
	}
	for(int i = 1;i <= m;++i){
		for(pr j : v[i]) {
			for(pr k : v[i]) {
				int p1 = j.first, p2 = k.first;
				if(p1 == p2) continue;
				int w1 = j.second, w2 = k.second;
				dis[p1][p2] = min(dis[p1][p2], (ll)w1 + w2);
				dis[p2][p1] = dis[p1][p2];
			}
		}
	}
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			if(dis[i][k] == INF) continue;
			for(int j = 1;j <= n;++j){
				ll x = dis[i][k] + dis[k][j], y = dis[i][j];
				dis[i][j] = (y > x ? x : y);
			}
		}
	}
	while(q--){
		int x, y;
		ll ans = INF;
		cin >> x >> y;
		for(pr i : v[x]) {
			for(pr j : v[y]) {
				int p1 = i.first, p2 = j.first;
				int w1 = i.second, w2 = j.second;
				ans = min(ans, dis[p1][p2] + w1 + w2 + ww[x] + ww[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}