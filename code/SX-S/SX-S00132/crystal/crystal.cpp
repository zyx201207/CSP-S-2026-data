#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500010], t, g, s, mmax;
map<int, int>m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = a[n] - a[i];
	for (int i = n; i > 0; i--) {
		s = 0, g = 1, t = i - 1;
		while (s <= k) {
			if (t < 1)
				break;
			s += a[t] - a[t + 1];
			g++, t--;
		}
		mmax = max(mmax, g - 1);
	}
	cout << mmax;
	return 0;
}