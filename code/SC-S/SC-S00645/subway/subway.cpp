#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 525, Station = 2e4 + 25;

int c, n, m, d, q;
int w[N], k;
int st, ed;

vector<int> lineForEachStation[Station];
int mp[Station][N];

vector<pair<int, int>> gra[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	vector<vector<int>> floyd(n + 25, vector<int>(n + 25, 1e18));
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		floyd[i][i] = 0;
		cin >> k;
		int tp, tj;
		for (int j = 1; j <= k; j++) {
			cin >> tj;
			lineForEachStation[tj].push_back(i);
			cin >> tp;
			mp[tj][i] = tp;
		}
	}
	
//	cout << "!1\n";
	
	for (int i = 1; i <= m; i++) {
		for (int lt1 = 0; lt1 < lineForEachStation[i].size(); lt1++) {
			int l1 = lineForEachStation[i][lt1];
			for (int lt2 = lt1 + 1; lt2 < lineForEachStation[i].size(); lt2++) {
				int l2 = lineForEachStation[i][lt2];
				if (l1 != l2) {
					gra[l1].push_back({l2, mp[i][l1] + mp[i][l2]});
					gra[l2].push_back({l1, mp[i][l1] + mp[i][l2]});
					floyd[l1][l2] = mp[i][l1] + mp[i][l2];
					floyd[l2][l1] = mp[i][l1] + mp[i][l2];
				}
			}
		}
	}
	
//	cout << "!2\n";
	
	
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || k == j || i == j) continue;
				if (floyd[i][j] + floyd[j][k] < floyd[i][k]) {
					floyd[i][k] = floyd[i][j] + floyd[j][k];
				}
			}
		}
	}
	
//	cout << "!3\n";
	
	
	for (int i = 1; i <= q; i++) {
		cin >> st >> ed;
		int ans = 1e18;
		for (auto l1 : lineForEachStation[st]) {
			for (auto l2 : lineForEachStation[ed]) {
				int l1r = w[st] + mp[st][l1], l2r = w[ed] + mp[ed][l2];
				if (floyd[l1][l2] + l1r + l2r < ans) {
					ans = floyd[l1][l2] + l1r + l2r;
				}
//				printf("st:%lld, ed:%lld, l1: %lld, l2:%lld, l1r:%lld, l2r:%lld, floyd:%lld; \n", st, ed, l1, l2, l1r, l2r, floyd[l1][l2]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}