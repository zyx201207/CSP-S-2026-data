#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
typedef long long ll;
const int N = 505, M = 5e5 + 5;
const ll INF = 2e18;
int w[M];
vector<pair<int, ll> > hv[M];
ll dist[N][N];
int n, m, d, q;
int main() {
	assert(freopen("subway.in", "r", stdin));
	assert(freopen("subway.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	int c;
	cin >> c >> n >> m >> d >> q;
	For(i, 1, m) cin >> w[i];
	For(i, 1, n) {
		int k;
		cin >> k;
		For(j, 1, k) {
			int a, t;
			cin >> a >> t;
			hv[a].push_back(mp(i, t));
		}
	}
	For(i, 0, n + 1) For(j, 0, n + 1) dist[i][j] = INF;
	For(i, 1, n) dist[i][i] = 0;
	For(i, 1, m) {
		int di = hv[i].size();
		For(j, 0, di - 1) {
			For(k, j + 1, di - 1) {
				dist[hv[i][k].x][hv[i][j].x] = dist[hv[i][j].x][hv[i][k].x] = min(dist[hv[i][j].x][hv[i][k].x], hv[i][j].y + hv[i][k].y);
			}
		}
	}
	For(k, 1, n) {
		For(i, 1, n) {
			For(j, 1, n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		int dx = hv[x].size();
		int dy = hv[y].size();
		For(i, 0, dx - 1) {
			For(j, 0, dy - 1) {
				int X = hv[x][i].x, Y = hv[y][j].x;
				ll now = dist[X][Y] + w[x] + w[y] + hv[x][i].y + hv[y][j].y;
				//cout << X << ' ' << Y << ' ' << dist[X][Y] << ' ' << w[X] << ' ' << w[Y] << ' ' << hv[x][i].y << ' ' << hv[y][j].y << '\n';
				ans = min(ans, now);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
