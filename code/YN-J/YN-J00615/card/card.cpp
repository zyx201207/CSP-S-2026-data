#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500001];
int w[300001];
int z[500001];
int c[300001];

int Count12(int l, int r) {
	for (int i = l; i <=  r ; i++) {
		cout << z[i] << " ";
		c[z[i]]++;
	}
	cout << "\n";
	for (int i = 1; i <= m; i++) {
		w[i] = 0;
	}
	return 0;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1;
	for (int i = 1; i <= n; i++) {
		int l1 = i;
		l = i - 1;
		for (int j = i; j <= n; j++) {
			if (w[a[j]] == 0) {
				z[j] = a[j];
				w[a[j]] = j;

				continue;
			}
			for (int ji = w[a[j]]; ji <= j - 1; ji++) {
				z[ji] = 0;
			}
			z[j] = a[j];
			w[a[j]] = j;
			l1 = j;
		}
		Count12(l1, n);
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}
