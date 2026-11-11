#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	int d = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = a[n]; j >= 1; j--) {

			if (a[i] == a[j]) {
				d++;
			}
		}
	}

	cout << d - 2 << " " << d - 3 << " " << d - 1 ;
	return 0;
}