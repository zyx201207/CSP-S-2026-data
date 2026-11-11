#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int a[N];
int f[N][N];
long long dis_min_cnt[N][N];

void solve() {
	memset(dis_min_cnt, 0, sizeof(dis_min_cnt));
	memset(f, 0, sizeof(f));
	
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; a[j] - a[i] <= d && j <= n; ++j) {
			f[i][j] = 1;
			dis_min_cnt[i][j] = 1;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			for (int k = i+1; k <= j-1; ++k) {
				if (f[i][k] == 0 || f[k][j] == 0) continue;
				if (k == i || k == j) continue;
				if (f[i][j] > f[i][k] + f[k][j] || f[i][j] == 0) {
					dis_min_cnt[i][j] = dis_min_cnt[i][k] * dis_min_cnt[k][j];
					f[i][j] = f[i][k] + f[k][j];
				} else if (f[i][j] == f[i][k] + f[k][j]) {
					dis_min_cnt[i][j] += dis_min_cnt[i][k] * dis_min_cnt[k][j];
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			ans += (dis_min_cnt[i][j] == 2) ? 1 : 0;
//			if (dis_min_cnt[i][j] == 2) {
//				cout << i << "," << j << endl;
//			}
		}
	}
	cout << ans << endl;
	
	return ;
	
}

int main() {
	freopen("migrate2.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}