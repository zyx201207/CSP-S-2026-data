#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10; 

int c, T, n, d, x[N], ans = INT_MAX, anss, tmp[N], flag[N];

vector<int> t[N];

void dfs(int xx, int y, int sum, int next) {
	if (xx == y) {
		ans = min(sum, ans);
		for (int i = 1; i <= n; i++) {
			tmp[i] = flag[i];
		}
		memset(flag, 0, sizeof flag);
		return ;
	}
	flag[xx] = 1;
	for (auto i : t[xx]) {
		if (flag[i] == 1 ||i == next) {
			continue;
		}
		dfs(i, y, sum + abs(x[xx] - x[i]), xx);
	}
	return ;
}

void dfs1(int xx, int y, int sum, int next) {
	if (xx == y) {
		if (ans == sum) {
			int tmpp = 0;
			for (int i = 1; i <= n; i++) {
				if (flag[i] != tmp[i]) {
					tmpp = 1;
					break;
				}
			}
			anss++;
		}
		return ;
	}
	flag[xx] = 1;
	for (auto i : t[xx]) {
		if (flag[i] == 1 || i == next) {
			continue;
		}
		dfs(i, y, sum + abs(x[xx] - x[i]), xx);
	}
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		sort(x + 1, x + n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					t[x[i]].push_back(x[j]);
					t[x[j]].push_back(x[i]);
				} else {
					break;
				}
			}
		}
		anss = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = 0;
				flag[i] = 1;
				dfs(i, j, 0, 0);
				memset(flag, 0, sizeof flag);
				flag[i] = 1;
				dfs1(i, j, 0, 0);
			}
		}
		cout << anss << '\n';
	}
	return 0;
}
