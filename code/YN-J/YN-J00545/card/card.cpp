#include <bits/stdc++.h>
using   namespace std;
int b[500005], c4[1000005];
int f[500005];

int ss(int m, int l) {
	int f = 0;

	for (int i = 0; i < m; i++) {

		if (f[i] = l) {
			f = i;
		}

	}

	return f;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int f = 0;
	int a, cnt = 0;
	cin >> a;

	for (int i = 0; i <= a; i++) {

		cin >> b[i];
		b[i] = f[i];
	}

	sort(f + 1, f + a + 1);

	for (int i = 0; i < a; i++) {

		c4[i] = ss(a, i);
	}

	cout << b[c4[1]];


	return 0;
}