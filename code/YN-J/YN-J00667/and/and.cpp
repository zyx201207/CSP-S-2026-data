#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans = pow(2, 30) - 1;
int n, m;
int maxn = INT_MIN;

bool cmp(int a, int b) {
	return a > b;
}
int res = -1;

void dg(int cnt, int j, int sum) {
	if (cnt == m + 1) {
		res = max(res, sum);
		return ;
	}
	for (int i = j + 1; i <= n + cnt - m; i++) {
		int sum1 = sum & a[i];
		dg(cnt + 1, i, sum1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		ans &= a[i];
	}
	if (m == 1) {
		cout << maxn;
	} else if (m == n) {
		cout << ans;
	} else if (maxn < 4) {
		sort(a + 1, a + 1 + n, cmp);
		cout << a[m];
	} else {
		dg(1, 0, pow(2, 30) - 1);
		cout << res;
	}
	return 0;
}

