#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 2, M = 502;
int n, m, d;
int w[N];
int D[N];
int to[N][21];
int t[N][21];
ll dis[M][M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int _C, q, x, y;
	cin >> _C >> m >> n >> d >> q;
	for(int i = 1; i <= n; ++ i){
		cin >> w[i];
	}

	for(int i = 1, k, a, _t; i <= m; ++ i){
		cin >> k;
		while(k --){
			cin >> a >> _t;
			++ D[a];
			to[a][D[a]] = i;
			t[a][D[a]] = _t;
		}
	}

	memset(dis, 0x3f, sizeof(dis));

	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= D[i]; ++ j){
			for(int k = j + 1; k <= D[i]; ++ k){
				int x = to[i][j], y = to[i][k];
				dis[x][y] = dis[y][x] = min(dis[x][y], (ll)t[i][j] + t[i][k]);
			}
		}
	}
	for(int i = 1; i <= m; ++ i){
		dis[i][i] = 0;
	}

	for(int k = 1; k <= m; ++ k){
		for(int i = 1; i <= m; ++ i){
			for(int j = 1; j <= m; ++ j){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	while(q --){
		cin >> x >> y;
		ll ans = 1e18;

		for(int i = 1; i <= D[x]; ++ i){
			for(int j = 1; j <= D[y]; ++ j){
				int a = to[x][i], b = to[y][j];
				ans = min(ans, dis[a][b] + t[x][i] + t[y][j]);
			}
		}

		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}

/*

g++ subway.cpp -o subway -std=c++14 -O2 -Wall
./subway

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/