#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500500], tx, s[500500], k = 1, biggg = -1e14, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long m1 = m, x;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			x = (a[j] - a[j - 1]) * k;
			if (x <= m1) {
				m1 = m1 - x;
				k++;
			} else {
				break;
			}
//			cout << k << ' ' << a[i] << ' ' << a[j] << endl;
		}
		biggg = max(k, biggg);
		k = 1;
		m1 = m;
	}
	cout << biggg;
	return 0;
}
//45分能拿省二吗TAT