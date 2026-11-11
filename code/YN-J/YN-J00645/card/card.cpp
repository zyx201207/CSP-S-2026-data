#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005], b[100005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	int q = 1;

	while (q <= m) {
		for (int i = q; i <= n; i++) {

			b[a[i]++];

			if (b[a[i]] >= 2) {
				a[i] = 0;
			}
		}

	}

	return 0;
}