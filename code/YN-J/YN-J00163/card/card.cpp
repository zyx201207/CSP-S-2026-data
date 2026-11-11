#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n];
	int k[n];//≥°…œ£ª

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		int num = 0;

		if (a[i] != k[i]) {
			k[i] = a[i];
		} else {
			for (int h = i; h <= k.size(); h++) {

				k[h] = 0;
			}

			k[i] = a[i];
		}

		for (int j = 1; j <= k.size(); j++) {

			if (k[j] == i) {

				num++;
			}
		}

		cout << num;
	}

	return 0;
}