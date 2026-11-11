#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5 + 10;
long long a[N], sum[N];
int ans;

bool check(int j, int i) {
	long long res = (i - j + 1) * a[i] - (sum[i] - sum[j - 1]);
	return res <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i, j;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, i))
				j = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;

	return 0;
}
