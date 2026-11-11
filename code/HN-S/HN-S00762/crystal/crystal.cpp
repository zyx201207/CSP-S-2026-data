#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500200];
signed main() {
	//freopen("crystal.in" , "r", stdin );
	//freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int mx, mn, ans = -0x3f3f3f3f3f3f3f3f;
	bool ok = true;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != a[2] - a[1]) ok = false;
	}
	if (ok == true) {
		for (int i = n; i >= 1; i--) {
			m -= a[n] - a[i];
			if (m < 0) {
				cout << n - i;
				return 0;
			}
		}
	}
	sort(a + 1, a + n + 1);
	mn = a[1];
	mx = a[n];
	for (int i = mn; i <= mx; i++){
		int sum = 0, t = 0;
		for (int j = n; j >= 1; j--) {
			if (a[j] > i) continue;
			else if (a[j] == i) t++;
			else {
				sum += i - a[j];
				if (sum > m) break;
				t++;
			}
		}
		ans = max(t, ans);
	}
	cout << ans;
	return 0;
} 
