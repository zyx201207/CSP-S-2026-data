#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[30001], b[30001], c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int l = 0;
		cin >> c;
		for (int j = 0; j < i; j++) {
			if (b[j] == c)
				l = j;
		}
		if (l = 0) {
			b[i] = c;
		} else {
			b[i] = c;
			for (int j = 0; j <= l; j++)
				b[j] = 0;
		}
		for (int j = 1; j <= i; j++) {
			a[b[i]]++;
		}
		for (int j = 0; i <= n; i++)
			cout << b[i] << ' ' << endl;
	}
	for (int i = 1; i <= m; i++)
		cout << a[i] << ' ';
	return 0;
}