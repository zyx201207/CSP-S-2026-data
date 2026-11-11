#include <bits/stdc++.h>
using namespace std;
int a[10001], b[100001], c[1000001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, n, j = 0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (a[x] == 0) {
			a[x] = i;
			b[j] = x;
		} else {
			for (int k = j + 1; k < i; k++)
				a[b[k]] = 0;
			j = a[x];
			a[x] = i;
		}
		for (int k = 1; k <= n; k++) {
			if (a[k] > 0)
				c[k]++;
		}
		j++;
	}
	for (int i = 1; i <= n; i++)
		cout << c[i];
	return 0;
}