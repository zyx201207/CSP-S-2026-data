#include <bits/stdc++.h>
#define int long long
#define inf 1e18

using namespace std;

const int N = 5e5 + 10, M = 520;

int c, n, m, d, q, x, y;
int ww[N], k[M], a[M][M], t[M][M], dist[M][M];
vector<pair<int, int> > get_dist[N];

int read(){
	int v = 0;char c = getchar();
	while (c < '0' || c > '9'){
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		v = v * 10 + (int)(c - '0');
		c = getchar();
	}
	return v;
}

void Floyd(){
	for (int k = 1; k <= n; k ++ ){
		for (int i = 1; i <= n; i ++ ){
			for (int j = 1; j <= n; j ++ ){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();n = read();m = read();d = read();q = read();
	for (int i = 1; i <= m; i ++ ){
		ww[i] = read();
	}
	for (int i = 1; i <= n; i ++ ){
		k[i] = read();
		for (int j = 1; j <= k[i]; j ++ ){
			a[i][j] = read();t[i][j] = read();
			get_dist[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= n; i ++ ){
		for (int j = 1; j <= n; j ++ ){
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= m; i ++ ){
		if (get_dist[i].size() >= 2){
			for (int j = 0; j < get_dist[i].size(); j ++ ){
				for (int z = j + 1; z < get_dist[i].size(); z ++ ){
					dist[get_dist[i][j].first][get_dist[i][z].first] = dist[get_dist[i][z].first][get_dist[i][j].first] = min(dist[get_dist[i][j].first][get_dist[i][z].first], get_dist[i][j].second + get_dist[i][z].second);
				}
			}
		}
	}
	Floyd();
	while (q -- ){
		x = read();y = read();
		int minn = INT_MAX;
		for (int i = 0; i < get_dist[x].size(); i ++ ){
			for (int j = 0; j < get_dist[y].size(); j ++ ){
				minn = min(minn, dist[get_dist[x][i].first][get_dist[y][j].first] + get_dist[x][i].second + get_dist[y][j].second);
			}
		}
		cout << minn + ww[x] + ww[y] << "\n";
	}
	return 0;
}

