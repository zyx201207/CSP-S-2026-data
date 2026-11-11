#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0;
	const int M = 3e5;
	int a[M];
	char b[M];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	int l = 1, r = n, x = a[l], y = a[r];
	while (l < r) {
		long long p;
		bool op = 1;
		if (b[l] == b[r])
			op = 0;
		if (x > y) {
			x -= y;
			r--;
			p = y;
			y = a[r];
		} else {
			y -= x;
			l++;
			p = x;
			x = a[l];
		}
		if (op)
			ans += p;
	}
	cout << ans;
	return 0;
}