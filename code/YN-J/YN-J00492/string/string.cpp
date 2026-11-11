//by ymxzz11 2026.10.31
//string
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n, ans;
int a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	while (l <= r) {
		if (a[l] < a[r]) {
			if (c[l] != c[r])
				ans += a[l];
			l++;
			a[r] -= a[l - 1];
		} else if (a[l] > a[r]) {
			if (c[l] != c[r])
				ans += a[r];
			r--;
			a[l] -= a[r + 1];
		} else {
			if (c[l] != c[r])
				ans += a[l];
			l++, r--;
		}
	}
	cout << (long long)ans;
	return 0;
}
