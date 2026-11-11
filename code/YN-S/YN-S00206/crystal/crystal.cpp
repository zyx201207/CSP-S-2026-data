#include <bits/stdc++.h>
using namespace std;
unsigned long long cnt = 0, n, m;
long long a[500005], b[500005], sum[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		sum[i] += a[i] + sum[i - 1];
		b[i] = (i * a[i]) - sum[i];

		if (b[i] > m && b[i - 1] <= m) {
			cout << i - 1;
			break;
		}
	}

	return 0;
}