#include <iostream>
#include <fstream>
using namespace std;

#define FILE_IO "subway"

#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define int long long

inline void chmax(int & a, int b) {
	if (a < b) a = b;
}
inline void chmin(int & a, int b) {
	if (a > b) a = b;
}

const int N = 1e6 + 5;
const int M = 505;
const int K = 25;
const int INF = 1e15;

int c, n, m, d, q;
int w[N];
int dis[M][M];
int cnt[N];
int sta[N][K], tim[N][K];

signed main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t; cin >> a >> t;
			cnt[a]++;
			sta[a][cnt[a]] = i;
			tim[a][cnt[a]] = t;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			int x = sta[i][j], dx = tim[i][j];
			for (int k = 1; k <= cnt[i]; k++) {
				int y = sta[i][k], dy = tim[i][k];
				// cout << "# " << x << " " << y << endl;
				chmin(dis[x][y], dx + dy);
				chmin(dis[y][x], dx + dy);
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i == j || j == k || i == k) continue;
				chmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (int _ = 1; _ <= q; _++) {
		int x, y; cin >> x >> y;
		int ans = INF;
		for (int i = 1; i <= cnt[x]; i++) {
			int p = sta[x][i], dp = tim[x][i];
			for (int j = 1; j <= cnt[y]; j++) {
				int q = sta[y][j], dq = tim[y][j];
				chmin(ans, dp + dq + dis[p][q]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
}
