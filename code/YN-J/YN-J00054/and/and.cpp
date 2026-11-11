#include <bits/stdc++.h>
using namespace std;

int a[2001];
int b[2001];


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m, maxn = -1;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	if (m == 2) {
		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if ((a[i] & a[j]) > maxn) {
					maxn = (a[i] & a[j]);
				}
			}
		}
	} else if (m == 1) {
		cout << 0;
		return 0;
	}

	cout << maxn;


	return 0;
}