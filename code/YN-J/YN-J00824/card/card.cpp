#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, a[500040], b[300040] = {0};
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (b[a[j]] == 1) {

			}
		}
	}

	return 0;
}
