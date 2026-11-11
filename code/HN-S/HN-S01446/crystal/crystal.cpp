#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[500005];
int diff[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	int k = a[(n + 1) / 2];
	for(int i = 1; i <= n; i++) {
		diff[i] = abs(k - a[i]);
	}
	sort(diff + 1, diff + n + 1);
	int ans = 0;
	for(int i = 1, j = m; i <= n, j > 0; i++) {
		j -= diff[i];
		ans++;
	}
	cout << ans;
	return 0;
} 
