#include <bits/stdc++.h>
#define int long long
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)
#define mp make_pair
#define pb push_back

const int N = 510, M = 5e5 + 10;
int dis[N][N], nouse[M], g[M][21], h[M][21], cnt[M];
int c, n, m, d, q;

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	FOR(i, 1, m) cin >> nouse[i];
	FOR(i, 1, n){
		int tmp, id, t;
		cin >> tmp;
		while(tmp--){
			cin >> id >> t;
			g[id][++cnt[id]] = t;
			h[id][cnt[id]] = i;
		}
	}

	FOR(i, 1, n) FOR(j, 1, n) dis[i][j] = 1e18;
	FOR(i, 1, n) dis[i][i] = 0;
	FOR(i, 1, m){
		FOR(j, 1, cnt[i]){
			FOR(k, j + 1, cnt[i]){
				dis[h[i][j]][h[i][k]] = min(dis[h[i][j]][h[i][k]], g[i][j] + g[i][k]);
			}
		}
	}
	FOR(i, 1, n) FOR(j, 1, n){
		dis[i][j] = min(dis[i][j], dis[j][i]);
		dis[j][i] = min(dis[j][i], dis[i][j]);
	}

	FOR(k, 1, n){
		FOR(i, 1, n){
			FOR(j, 1, n){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	while(q--){
		int x, y, res = 1e18;
		cin >> x >> y;
		FOR(i, 1, cnt[x]) FOR(j, 1, cnt[y]){
			res = min(res, g[x][i] + g[y][j] + dis[h[x][i]][h[y][j]]);
		}
		cout << res + nouse[x] + nouse[y] << '\n';
	}
	return 0;
}
/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
*/