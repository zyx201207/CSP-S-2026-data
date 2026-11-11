#include <bits/stdc++.h>
using namespace std ;
int m, n;

int a[200010], c[200020], cnt[200010] = {0};

bool v[300010] = {0};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = i; j < n; j++) {
			if (v[c[j]] == 1) {
				v[c[j]] = 0;
				while (a[x] != c[j]) {
					a[x] = 0;
					x--;
				}
				x++;
				continue;
			} else {
				a[x] = c[j];
				v[c[j]] = 1;
				x++;
			}
		}
		for (int y = 0; y <= x; y++) {
			cnt[a[y]]++;
		}
		memset(a, n, 0);
		memset(v, n, 0);
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}

	return 0;
}