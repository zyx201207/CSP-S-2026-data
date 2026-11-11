#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long a[200005];
long long pre[200005];

void dfs(long long cur, long long sum, long long cnt) {
	if (cur == n + 1) {
		if (cnt == m) {
			ans = max(ans, sum);
		}

		return;
	}

	if (cnt == m) {
		ans = max(ans, sum);
		return;
	}

	dfs(cur + 1, sum & a[cur], cnt + 1);
	dfs(cur + 1, sum, cnt);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	dfs(1, pow(2, 31) - 1, 0);
	cout << ans << endl;
	return 0;
}