#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, i, j, k, l;
	cin >> n >> m;
	int a[n], b[m + 1] = {0}, a2[n] = {-1};
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		for (j = i, l = i; j < n; j++) {
			for (k = l - 1; k == -1 || a2[k] == a2[l]; k--) {}
			if (k == -1) {
				a2[j] = a[i];
				l = j + 1;
			} else {
				l++;
			}
		}
		for (j = 0; j < l; j++)
			if (b[a2[j]] <= i)
				b[a2[j]]++;
	}
	for (i = 1; i <= m; i++)
		cout << b[i] << ' ';
	return 0;
}