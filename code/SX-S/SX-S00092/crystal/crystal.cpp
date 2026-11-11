#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], sum[500005], maxn = 1, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	long long pos = 1;
	for (int i = 1; i <= n; i++) {
		if ((i - pos) * a[i] - (sum[i - 1] - sum[pos - 1]) <= m) {
			maxn = max(maxn, i - pos + 1);
		} else {
			pos++;
		}
	}
	cout << maxn;
	return 0;
}
