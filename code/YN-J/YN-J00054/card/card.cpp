#include <bits/stdc++.h>
using namespace std;

int a[200001];
int b[2];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = i + 1; j <= n; j++) {

			for (int z = i; z < j; z++) {

				if (a[j] == a[z]) {
					for (int q = z; q <= j - 1; q++) {

						a[q] = 0;
					}
				}
			}
		}
	}

	return 0;
}