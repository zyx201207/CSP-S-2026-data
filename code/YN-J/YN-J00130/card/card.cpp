#include <bits/stdc++.h>
using namespace std;
int n, m, q, q1, sum = 0;
int a[100005], b[100005], c[100005], aa[100005];
int num[100005];
int d[100005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int n1 = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		num[i] = 0;
		d[i] = a[i];
		aa[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int jj = 1; jj <= n; jj++)
			d[jj] = 0;
		for (int j = n; j >= 1; j--) {
			for (int l = i; l <= j; l++) {
				if (a[j] == b[l]) {
					q = l;
				}
				q1 = l;
			}
		}
		for (int p = 1; p <= q; p++)
			d[p] = -1;
		for (int j = 1; j <= n; j++) {
			if (d[j] != -1)
				num[b[j]]++;
		}
		for (int p = 1; p <= q; p++) {
			if (d[p] == -1)
				sum++;
		}
		for (int y = 1; y <= n; y++) {
			int u = 1;
			if (d[y] != -1) {
				if (u <= sum)
					a[u] = aa[y];
				u++;
			}
		}
		for (int k = 1; k <= sum; k++) {
			b[k] = a[k];
		}
		for (int x = 1; x <= m; x++) {
			cout << num[x] << ' ';
		}
	}
	return 0;
}