#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<char> c(n + 1);
	int L = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		L += a[i];
	}
	int ans = 0;
	for (int i = 1, j = n;;) {
		if (i >= j) {
			break;
		}
		if (a[i] > a[j]) {
			if (c[i] == c[j]) {
				a[i] -= a[j];
				a[j] = 0;
				
			}
			else {
				a[i] -= a[j];
				ans += a[j];
				a[j] = 0;
			}
			j--;
		}
		else if (a[i] < a[j]){
			if (c[i] == c[j]) {
				a[j] -= a[i];
				a[i] = 0;
			}
			else {
				a[j] -= a[i];
				ans += a[i];
				a[i] = 0;
			}
			i++;
		}
		else {
			if (c[i] == c[j]) {
				a[i] = a[j] = 0;
				
			}
			else {
				ans += a[i];
				a[i] = a[j] = 0;
			}
			i++;
			j--;
		}
	} 
	cout << ans << '\n';
	return 0;
}
