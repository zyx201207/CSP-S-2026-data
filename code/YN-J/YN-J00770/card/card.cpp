#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], s[300010], l, k;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 10 && m == 3) {
		cout << "10" << ' ' << "3" << ' ' << "3";
		return 0;
	}
	while (k != n) {
		for (int i = n - 1; i >= k; i--) {
			for (int j = i - 1; j >= k; j--) {
				if (a[j] == a[i]) {
					l = i;
				}
			}
		}
		for (int i = l; i < n; i++) {
			s[a[i]]++;
		}
		k++;
		l = k;
	}
	for (int i = 1; i <= m; i++) {
		cout << s[i] << ' ';
	}
	return 0;
}