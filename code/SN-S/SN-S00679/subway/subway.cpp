#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], k[505], a[505][50005], t[505][50005], f[505][505], ff[505], minn;
vector<pair<long long, long long> > v[505];
void dfs(long long x, long long y, long long num){
	if(x == y){
		minn = min(minn, num);
		return;
	}
	for(int i = 0; i < v[x].size(); i ++){
		long long tt = v[x][i].second, nx = v[x][i].first;
		if(ff[nx] == 1) continue;
		ff[nx] = 1;
		dfs(nx, y, num + tt);
		ff[nx] = 0;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j <= k[i]; j ++){
			for(int l = 1; l <= k[i]; l ++){
				v[a[i][j]].push_back({a[i][l], t[i][j] + t[i][l]});
				v[a[i][l]].push_back({a[i][j], t[i][l] + t[i][j]});
				f[a[i][l]][a[i][j]] = min(f[a[i][l]][a[i][j]], t[i][l] + t[i][j]);
				f[a[i][j]][a[i][l]] = min(f[a[i][j]][a[i][l]], t[i][l] + t[i][j]);
			}
		}
	}
	while(q --){
		long long x, y;
		cin >> x >> y;
		if(f[x][y]){
			cout << f[x][y] << endl;
			continue;
		}
		minn = 1e18;
		dfs(x, y, 0);
		f[x][y] = minn;
		f[y][x] = minn;
		cout << minn + w[x] + w[y] << endl;
	}
	return 0;
}

