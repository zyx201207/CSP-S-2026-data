#include<bits/stdc++.h>

#define int long long

using namespace std;

int a[500005];
int sm[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sm[i] = sm[i - 1] + a[i];
	int l = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		while (l <= i and a[i] * (i - l + 1) - (sm[i] - sm[l - 1]) > k) l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}