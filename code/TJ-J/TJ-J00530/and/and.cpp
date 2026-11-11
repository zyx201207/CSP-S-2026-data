//BL 6~10/20 (25分)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,m;
ll a[200010];
ll ans = INT_MIN;

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	if (m == 1) {
		sort (a + 1,a + n + 1);
		cout << a[n] << "\n";
		return 0;
	} else if (m == 2) {
		for (int i = 1;i <= n;i++) {
			for (int j = i + 1;j <= n;j++) {
				ll t = a[i] & a[j];
				ans = max (ans,t);
			}
		}
		cout << ans << "\n";
		return 0;
	} else if (m == n) {
		ans = a[1];
		for (int i = 2;i <= n;i++) {
			ans &= a[i];
		}
		cout << ans << "\n";
		return 0;
	} else {//特殊性质A  (样例2) 
		ans = a[n];
		sort (a + 1,a + n + 1);
		for (int i = 1;i <= m;i++) {
			ans &= a[n - i + 1];
		}
		cout << ans << "\n";
	}
	return 0;
}
