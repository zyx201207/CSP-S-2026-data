#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int b[500005];
int c[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n  >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] == a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (b[j] == b[i]) {
				for (int k = i; k <= j; k++)
					b[k] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] != 0)
				c[b[i]]++;
		}
		for (int i = 1; i <= n; i++)
			b[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] != 0)
			cout << c[i] << ' ';
	}
	return 0;
}
