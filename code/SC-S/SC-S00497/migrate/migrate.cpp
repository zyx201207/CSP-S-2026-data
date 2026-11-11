#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int fvv, T;

const int N = 2e6 + 5, inf = 2e9;
int n, dp[N];
ll d, a[N], fnl;
int R[N], L[N];

int ways[N];
void dfs (int x, int cnt) {
	ways[x] ++;
	for (int y = x + 1; y <= R[x]; ++ y) {
		if (cnt + 1 > dp[y]) continue;
		dfs(y, cnt + 1);
	}
}

inline void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	int cur = n;
	for (int i = n; i; -- i) {
		while (cur > i and a[cur] - a[i] > d) cur --;
		R[i] = cur;
	}
	cur = 1;
	for (int i = 1; i <= n; ++ i) {
		while (cur < i and a[i] - a[cur] > d) cur ++;
		L[i] = cur;
	}
	fnl = 0;
	for (int i = 1; i <= n; ++ i) {
		dp[i] = 0;
		for (int j = i + 1; j <= n; ++ j) {
			dp[j] = inf;
			ways[j] = 0;
			for (int k = max(i, L[j]); k <= j - 1; ++ k)
				dp[j] = min(dp[j], dp[k] + 1);
		}
//		if (T and i == 1) for (int j = 2; j <= n; ++ j) cout << dp[j] << ' ';
		dfs(i, 0);
		for (int j = i + 1; j <= n; ++ j) {
			fnl += (ways[j] == 2);
//			if (ways[j] == 2) cout << i << ' ' << j << '\n';
		}
	}
	cout << fnl << '\n';
}

inline void solveA () {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	ll len = d / (a[2] - a[1]);
//	cout << n << ' ' << len << '\n';
	if (len <= 1) return cout << "0\n", void();
	cout << max((ll)n - (len * 2 - 1), 0ll) << '\n';
}

inline void solveB () {
	cout << "0\n";
	return;
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	int cur = n;
	for (int i = n; i; -- i) {
		while (cur > i and a[cur] - a[i] > d) cur --;
		R[i] = cur;
	}
	cur = 1;
	for (int i = 1; i <= n; ++ i) {
		while (cur < i and a[i] - a[cur] > d) cur ++;
		L[i] = cur;
	}
	int mid = 0;
	for (int i = 1; i <= n; ++ i) {
		if (L[i] == 1 and R[i] == n) {
			mid = i; break;
		}
	}
	ll lf = 0, rt = 0;
	for (int i = 1; i < mid; ++ i) {
		lf += (R[i] == mid);
	}
	for (int i = mid + 1; i <= n; ++ i) {
		rt += (L[i] == mid);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> fvv >> T;
	while (T --) {
		if (fvv == 11 or fvv == 12) solveA();
		else if (fvv == 13 or fvv == 14) solveB();
		else solve();
	}
	return 0;
}

/*
0 1
10 5
1 2 3 4 5 6 7 8 9 10
*/
