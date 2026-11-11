#include <bits/stdc++.h>
using namespace std;
long long a[64534];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int q, w;
	cin >> q >> w;
	for (int i = 1; i <= q; i++) {
		cin >> a[i];
	}
	for (int l = 1; l <= w; l++) {
		for (int i = 1; i <= 2; i++) {
			if (a[w] == 1) {
				cout << a[w] + a[w - 1] << " ";
				break;
			} else {
				cout << q << " ";
				break;
			}
		}

		for (int i = 1; i <= 2; i++) {
			if (a[1] == 2) {
				cout << a[1] << " ";
				break;
			} else {
				cout << a[1] << " ";
				break;
			}
		}

		for (int i = 1; i <= 2; i++) {
			cout << a[q] + a[q - 1] << endl;
			break;
		}

	}

	return 0;
}