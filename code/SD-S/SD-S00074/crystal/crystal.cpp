#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;
long long a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (1ll * a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) > m) l = mid + 1;
			else r = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}

// a[r + 1] * (r - l + 1) - (sum[r] - sum[l - 1]) 
