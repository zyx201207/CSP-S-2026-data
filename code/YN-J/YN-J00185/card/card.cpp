#include <bits/stdc++.h>
using namespace std;

int n, m, l, a[500005], b[300005], c[500005];
bool f = 1;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1])
			f = 0;
	}
	if (f == 1) {
		for (int i = 2; i <= n + 1; i++)
			if (a[i] != a[i - 1])
				cout << i - 1 << ' ';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(c, 0, sizeof c);
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= l; k++)
				if (c[k] == a[j]) {
					for (int m = k; m <= l; m++)
						c[m] = 0;
					l = k - 1;
					break;
				}
			c[++l] = a[j];
		}
		for (int j = 1; j <= l; j++)
			b[c[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << b[i] << ' ';
	return 0;
}