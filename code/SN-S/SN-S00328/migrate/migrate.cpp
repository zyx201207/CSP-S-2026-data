#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 2e6 + 10;

namespace Solver {
	int n;
	i64 d;
	int s[N];
	i64 t[N];
	void init() {
		memset(s, 0, sizeof s);
		memset(t, 0, sizeof t);
	}
	void solve1() {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> t[i];
		}
		s[n] = 0;
		for (int l = n - 1; l >= 1; --l) {
			s[l] = s[l + 1] + 1;
			while (t[l + s[l]] - t[l] > d) s[l]--;
		}
		
		bool flag2 = true;
		for (int i = 3; i <= n; ++i) if (t[i] - t[i - 1] != t[i - 1] - t[i - 2]) flag2 = false;
		if (flag2) {
			i64 c = t[2] - t[1];
			int cnt = n - s[1] * 2 + 1;
			if (cnt <= 0) cout << "0\n";
			else if (s[1] < 2) cout << "0\n";
			else {
				cout << cnt << '\n';	
			}
			return;
		}
		
		if (n >= 5000) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (i + s[i] < n) {
					cnt += n - i - s[i];
				}
			}
			cout << cnt << '\n';
			return;
		} 
		
		int cnt = 0;
		for (int i = 1; i < n; ++i) {
			vector<int> dp(n + 1, 0);
			vector<int> dc(n + 1, 1e9);
			dc[i] = 0, dp[i] = 1;
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j - 1; k >= i; --k) {
					if (k + s[k] < j) break;
					if (dc[k] + 1 < dc[j]) {
						dc[j] = dc[k] + 1;
						dp[j] = dp[k];
					} else if (dc[k] + 1 == dc[j]) {
						dp[j] += dp[k];
					}
				}
				if (dc[j] != 0 && dp[j] == 2) ++cnt;
			}
		}
		cout << cnt << '\n';
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		Solver::init();
		Solver::solve1();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
