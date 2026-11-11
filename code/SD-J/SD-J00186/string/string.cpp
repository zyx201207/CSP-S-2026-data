#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul; 
ul n;
ul a[200005];
char c[200005];
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio ();
	cin.tie (0), cout.tie (0);
	cin >> n;
	for (int i = 1;i <= n; ++i)
		cin >> a[i] >> c[i];
	ul l = 1, r = n;
	ul ans = 0;
	while (l <= r) {
		if (a[l] == a[r]) {
			if (c[l] != c[r])
				ans += a[l];
		}
		else if (a[l] < a[r]) {
			if (c[l] != c[r])
				ans += a[l];
			a[r] = a[r] - a[l];
			r++;
		}
		else if (a[r] < a[l]) {
			if (c[l] != c[r])
				ans += a[r];
			a[l] = a[l] - a[r];
			l--;
		}
		l++, r--;
	}
	cout << ans << '\n';
	return 0;
} 
//ChatGPT Éú³É 
