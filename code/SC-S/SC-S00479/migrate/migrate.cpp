#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

const int inf = LONG_LONG_MAX;
int n, d;
vector<int>x;

namespace solveA {
	void sol() {
		int dif = x[2] - x[1];
		int s = d / dif;
		if (s <= 1) {
			cout << 0 << "\n";
			return;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i + 2 * s - 1 <= n)
				ans++;
			else
				break;
		}
		cout << ans << "\n";
		return;
	}
}

namespace solve {
	int minn = inf;
	vector<int>cnt;
	void dfs(int u, int step, int ed) {
		if (u == ed) {
			if (step < minn)	minn = step;
			cnt[step]++;
			return;
		}
		for (int v = u + 1; v <= ed; v++) {
			if (x[v] - x[u] > d || step + 1 > minn)	break;
			dfs(v, step + 1, ed);
		}
	}
	void sol() {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				minn = inf;
				cnt.assign(10, 0);
				dfs(i, 0, j);
				if (cnt[minn] == 2)	ans++;
			}
		cout << ans << "\n";
	}
}

void work() {
	cin >> n >> d;
	x.resize(n + 5);
	bool A = 1, B = 1, C = 0;
	int dif = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (i == 2)
			dif = x[i] - x[i - 1];
		if (i > 2 && x[i] - x[i - 1] != dif)
			A = 0;
	}
	if (x[n] - x[1] <= 10 * d)		C = 1;
	if (n == 1) {
		cout << 0 << "\n";
		return;
	}
	if (A)	solveA::sol();
	else if (n <= 9)	solve::sol();
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while (T--)	work();
	return 0;
}
