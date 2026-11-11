#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 100;
int n, sum;
char cc;
int a[N];
char c[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i] >> c[i];
		if (c[i] > 'z' || c[i] < 'a') cin >> c[i];
	}
	int L = 1, R = n, l = 0, r = 0;
	while (L < R) {
		if (a[L] - l < a[R] - r) {
			if (c[L] != c[R]) sum += a[L] - l;
			r += a[L] - l;
			l = 0;
			++ L;
		}
		else if (a[L] - l > a[R] - r) {
			if (c[L] != c[R]) sum += a[R] - r;
			l += a[R] - r;
			r = 0;
			-- R;
		}
		else {
			if (c[L] != c[R]) sum += a[L] - l;
			l = r = 0;
			++ L; -- R;
		}
	}
	cout << sum << '\n';
	return 0;
}
