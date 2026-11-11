#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal4.in", "r", stdin);
	freopen("crystal4.out", "w", stdout);
	int n, m, l = 0, s = 0;
	cin >> n >> m;
	int a[1001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j > 0 || j < n) {
				l += a[j + 1];
				l += a[j - 1];
			} else if (j == 0)
				l += a[j + 1];
			else if (j == n)
				l += a[j - 1];
		}
		l += m;
		l /= i;
		for (int j = 0; j < n; j++) {
			if (l == a[j])
				s += j;
			s += 1;
		}
	}
	cout << s;
	return 0;
}