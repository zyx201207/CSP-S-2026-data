#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], b[N];
int n, m;

bool cmp(int a, int b) {
	return a > b;
}

bool vis[N];
int maxx = INT_MIN;

void dfs(int step) {
	if (step > m) {
		int ans = b[1];
		for (int i = 2; i <= m; i++) {
			ans &= b[i];
		}
		maxx = max(maxx, ans);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)
			continue;
		b[step] = a[i];
		vis[i] = 1;
		dfs(step + 1);
		vis[i] = 0;
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m > 1 && m <= 5) {
		dfs(1);
		cout << maxx;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}


