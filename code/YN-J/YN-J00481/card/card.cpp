#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5e5 + 10;
int a[N], c[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int w = n;
	int l = 1;
	while (w--) {
		int b[N] = {0};
		int r = 0;
		for (int i = l; i <= n; i++) {
			r++;
			b[r] = a[i];
			for (int j = 1; j < r; j++) {
				if (b[j] == b[r]) {
					for (int k = j; k < r; k++)
						b[k] = 0;
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			if (b[i])
				c[b[i]]++;
		}
		l++;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i])
			cout << c[i] << " ";
	}
	return 0;
}