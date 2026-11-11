#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 510, M = 5e5 + 10;
const long long INF = 1e18;
int c, n, m, d, q;
int w[M], tim[N][M];
LL trans[N][N];
vector<int> line[M];

int main(){

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(tim, 0x3f, sizeof(tim));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k, a;
		LL t;
		cin >> k;
		while (k--) {
			cin >> a >> t;
			line[a].push_back(i);
			tim[i][a] = t;
		}
	}


	memset(trans, 0x3f, sizeof(trans));
	for (int i = 1; i <= m; ++i) {
		for (int idx1 = 0; idx1 < line[i].size(); ++idx1) {
			int l1 = line[i][idx1];
			for (int idx2 = 0; idx2 < idx1; ++idx2) {
				int l2 = line[i][idx2];
				trans[l1][l2] = min(trans[l1][l2], 1ll * tim[l1][i] + tim[l2][i]);
				trans[l2][l1] = trans[l1][l2];
			}
			trans[l1][l1] = 0;
		}
	}


	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
			}
		}
	}

	while (q--) {
		int st, ed;
		cin >> st >> ed;

		LL ans = INF;
		for (int i = 0; i < line[st].size(); ++i) {
			int st_line = line[st][i];
			for (int j = 0; j < line[ed].size(); ++j) {
				int ed_line = line[ed][j];
				ans = min(ans, trans[st_line][ed_line] + tim[st_line][st] + tim[ed_line][ed]);
			} 
		}
		cout << ans + w[st] + w[ed] << "\n";
	}
	return 0;
}
