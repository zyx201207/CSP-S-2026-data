#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) b[i] = b[i - 1] + a[i];
	long long maxn = 0;
	for (int i = 1; i <= n; i++) {
		long long l = i, r = n, ans = 0;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if ((mid - i + 1) * a[mid] - b[mid] + b[i - 1] <= m) l = mid + 1, ans = mid - i + 1;
			else r = mid - 1;
		} maxn = max(maxn, ans);
	} cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
