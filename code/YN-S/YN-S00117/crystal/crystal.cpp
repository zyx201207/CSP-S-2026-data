#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m, a[N], sum[N];

void work(int k) {
	int l = 1, r = k;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if  ((sum[k] - sum[mid - 1]) + m >= (k - mid + 1)*a[k]) {
			r = mid - 1;
			ans = max(ans, k - mid + 1);
		} else
			l = mid + 1;
	}
}

int main() {
	freopen("crystal.in ", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		work(i);
	cout << ans;
	return 0;
}