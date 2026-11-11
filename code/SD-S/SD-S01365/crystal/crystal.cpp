#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n; ll m;
ll a[500010];
ll b[500010]; ll sum;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i]; sort(a + 1, a + 1 + n);
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j + 1 <= n && a[j + 1] == a[j]) ++j;
		
		int l = 0, r = i - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;

			if (b[i - 1] - b[i - 1 - mid] + 1ll * mid * sum <= m) l = mid;
			else r = mid - 1;
		} ans = max(ans, l + j - i + 1);
		
		for (int k = i; k <= j; ++k)
			b[k] = b[k - 1] - sum;
		sum += a[j + 1] - a[j];  i = j;
	}
	
	cout << ans << "\n";

	return 0;
}
