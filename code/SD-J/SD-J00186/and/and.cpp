#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul; 
ll n, m;
ul a[200005];
bool vis[200005];
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio ();
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n; ++i)
		cin >> a[i];
	if (m == n) {
		ul sum = 0;
		for (int i = 1;i < n; ++i)
			sum += a[i] & a[i + 1];
		cout << sum << '\n';
		return 0;
	}
	if (m == 1) {
		ul maxn = 0;
		for (int i = 1;i <= n; ++i)
			maxn = max (maxn, a[i]);
		cout << maxn << '\n';
		return 0;
	}
	if (m == 2) {
		ul maxn = 0;
		for (int i = 1;i <= n; ++i)
			for (int j = i + 1;j <= n; ++j)
				maxn = max (maxn, a[i] & a[j]);
		cout << maxn << '\n';
		return 0;
	}
	if (m == n - 1) {
		for (int i = 1;i <= m; ++i)
	}
	else {
		ul sum = 0, ans = 0;
		for (int l = 1;l <= n; ++l) {
			sum = a[l];
			for (int i = 0;i <= n; ++i) 
				vis[i] = false;
			vis[l] = true;
			for (int i = 1;i <= m; ++i) {
				ul maxn = 0;
				for (int kk = 1;kk <= n; ++kk) {
					if (!vis[kk]) {
						maxn = a[kk], vis[kk] = true;
						break;
					}
				}
				for (int k = 1;k <= n; ++k) {
					if (!vis[k]) {
						if (sum & maxn < sum & a[k])
							maxn = a[k];
					}
				}
				sum = sum & maxn;
			}
			ans = max (ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
} 
//ChatGPT Éú³É 
