#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int c, n, m, d, q;
int w[5001];
int k[501];
vector<int> a[501], t[501];
int tmp;
int x, y;

long long minn;

long long dis[501][501];

int sta[100001][21], len[100001];
long long lon[100001][501];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> tmp;
			a[i].push_back(tmp);
			cin >> tmp;
			t[i].push_back(tmp);
			sta[a[i].back()][++len[a[i].back()]] = i;
			lon[a[i].back()][i] = t[i].back();
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int i1 = 0; i1 < a[i].size(); ++i1) {
				for (int j1 = 0; j1 < a[j].size(); ++j1) {
					if (a[i][i1] == a[j][j1]) {
						dis[i][j] = t[i][i1] + t[j][j1];
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= n; ++l) {
				dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
			}
		}
	}
	for (int r = 1; r <= q; ++r) {
		minn = 1e18;
		cin >> x >> y;
		for (int i = 1; i <= len[x]; ++i) {
			for (int j = 1; j <= len[y]; ++j) {
				minn = min(minn, lon[x][sta[x][i]] + dis[sta[x][i]][sta[y][j]] + lon[y][sta[y][j]]);
			}
		}
		cout << minn + w[x] + w[y] << '\n';
	}
	return 0;
}
