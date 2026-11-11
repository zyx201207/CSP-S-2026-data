#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2005], num;
char c[2005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];	
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] != c[n - i + 1] && (a[i] != 0 && a[n - i + 1] != 0)) {
			num += min(a[i], a[n - i + 1]);
			if (a[i] >= a[n - i + 1]) {
				a[i] -= a[n - i + 1];
				a[n - i + 1] = 0;
				c[n - i + 1] = c[i];
			}
			else {
				a[n - i + 1] -= a[i];
				a[i] = 0;
				c[i] = c[n - i + 1];
			}
			
		}
	}
	cout << num;
}
