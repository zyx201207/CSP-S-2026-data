# include <bits/stdc++.h>
# define ll long long
# define pii pair <ll, char>
using namespace std;

ll a[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	bool f1 = true;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != i - 1) f1 = false;
		
	}
	
	sort(a + 1, a + n + 1);
	
	ll ans = -1;
	
	if (f1) {
		ans = a[n];
		for (int i = n - 1;i >= n - m + 1; i --) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}

	
	for (int i = n; i >= m; i--) {
		ll tm = a[i], tmp = 1;
		if (double(clock()) / CLOCKS_PER_SEC > 0.9) break;
		
		for (int j = i - 1; j >= 1; j --) 
			if ((tm & a[j]) && (tmp < m)) tmp ++, tm &= a[j];
		if(tmp == m) ans = max(ans, tm);
		
	}
	cout << ans;
	return 0;
}
