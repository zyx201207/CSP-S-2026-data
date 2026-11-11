#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long n, a[N], ans;
char c[N];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	long long l = 1, r = n, left = a[1], right = a[n];
	while (l < r) {
		if  (left == right) {
			if (c[l] != c[r]) ans += left;
			left = a[++ l]; right = a[-- r];
		}
		if (left < right) {
			if (c[l] != c[r]) ans += left;
			right -= left;
			left = a[++ l];
		}
		if (left > right) {
			if (c[l] != c[r]) ans += right;
			left -= right;
			right = a[-- r];
		}
	}
	cout << ans;
}
