#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d;
const int N = 2e6 + 6;
long long a[N], sum[N];

void optB() {
	int cen = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] - sum[1] <= d && sum[n] - sum[i] <= d)
			cen = i;
	}
	for (int i = 1; i < cen; i++)
		for (int j = cen + 1; j <= n; j++) {
			bool left_island = 0, right_island = 0;
			if (sum[j] - sum[i] <= d)
				continue;
			if (sum[j] - sum[cen - 1] <= d) {
				if (sum[j] - sum[cen - 2] > d)
					left_island = 1;
			}
			if (sum[cen + 1] - sum[i] <= d) {
				if (sum[cen + 2] - sum[i] > d)
					right_island = 1;
			}
			if ((left_island && !right_island) || (!left_island && right_island)) {
				ans++;
			}
		}
	cout << ans << '\n';
	return;
}

void optA() {
	int pd = a[2] - a[1];
	int k = d / pd;
	long long ans = max(n - 2 * k + 1, 0);
	cout << ans << '\n';
	return;
}

void optT() {
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[n] - sum[i] <= d)
			break;
		int r = upper_bound(sum + 1, sum + n + 1, sum[i] + 2 * d) - sum;
		r--;
		int mid = upper_bound(sum + 1, sum + n + 1, sum[i] + d) - sum;
		mid--;
		if (sum[r] - sum[mid] > d)
			continue;
		if (sum[r] - sum[mid] == d && sum[mid] - sum[i] == d)
			continue;
		for (int j = mid + 1; j <= r; j++) {
			if (sum[j] - sum[mid - 1] <= d)
				if (sum[j] - sum[mid - 2] > d)
					ans++;
		}
	}
	cout << ans << '\n';
	return;
}

int main() {
	freopen("migrate.in ", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		cin >> a[1];
		for (int i = 2; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i] - a[i - 1];
		}
		if (c == 13 || c == 14) {
			optB();
		} else if (c == 11 || c == 12) {
			optA();
		} else {
			optT();
		}
	}
	return 0;
}
