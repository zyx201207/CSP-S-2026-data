#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 505;
int _, n, m, d, q, w[N], dis[M][M];
vector<pair<int, int> > v[N], vv[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	cin >> _ >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)	cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int na, nt;
			cin >> na >> nt;
			v[na].emplace_back(make_pair(i, nt));
			vv[i].emplace_back(make_pair(na, nt));
		}
	}
	for(int i = 1; i <= n; i++){
		dis[i][i] = 0;
		for(auto j : vv[i]){
			int a = j.first, t = j.second;
			for(auto l : v[a]){
				int p = l.first, val = l.second;
				dis[i][p] = min(dis[i][p], t + val);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y, ans = 2e18;
		cin >> x >> y;
		for(auto i : v[x]){
			int a = i.first, val1 = i.second;
			for(auto j : v[y]){
				int b = j.first, val2 = j.second;
				ans = min(ans, dis[a][b] + val1 + val2);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}