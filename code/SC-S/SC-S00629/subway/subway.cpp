#include<bits/stdc++.h>
#define _for(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 505, K = 5e5 + 5;
int c, n, m, d, q;
int w[K], k[N], a[N][K], t[N][K], x, y;
int ans, ti[K][25];
vector<pair<int, int>> es[K];
vector<int> v[K], mi(K);
vector<bool> fl(K);
void dfs(int u, int xl, int cnt){
	if(u == y){
		ans = min(ans, cnt);
		return ;
	}
	fl[u] = true;
	for(auto v : es[u]) if(!fl[v.first]){
		int t = 0;
		if(v.second != xl) t += ti[u][xl] + ti[u][v.second];
		dfs(v.first, v.second, cnt + t);
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	_for(i, 1, m) cin >> w[i];
	_for(i, 1, n){
		cin >> k[i];
		_for(j, 1, k[i]){
			cin >> a[i][j] >> t[i][j];
			ti[a[i][j]][i] = t[i][j];
			v[a[i][j]].push_back(i);
		}
		_for(j, 1, k[i]){
			if(j != 1) es[a[i][j]].push_back({a[i][j - 1], i});
			if(j != k[i]) es[a[i][j]].push_back({a[i][j + 1], i});
		}
	}
	_for(i, 1, q){
		ans = 1e9;
		cin >> x >> y;
		_for(i, 0, v[x].size() - 1){
			_for(i, 0, m - 1) fl[i] = false;
			dfs(x, v[x][i], w[x]);
		}
		cout << ans + w[y] << '\n';
	}
	return 0;
}