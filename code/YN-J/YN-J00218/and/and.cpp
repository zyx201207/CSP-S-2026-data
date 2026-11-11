#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int s, max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < i + m; j++) {
			for (int k = 0; k < m; k++) {
				s = a[i] && a[i + 1];

			}
			if (s > max) {
				max = s;
			}
			s = 0;
		}
	}
	cout << max;
	return 0;
}