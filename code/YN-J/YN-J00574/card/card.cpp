#include <bits/stdc++.h>
using namespace std;
int a[500005];
int a2[500005];
int b[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x = 1;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i2 = 1; i2 <= n; i2++) {
		for (int i = x ; i <= n; i++) {
			a2[k] = a[i];
			for (int j = 1; j <= i; j++) {
				if (a2[i] == a2[j]) {
					for (int k2 = j; k2 < i; k2++) {
						a2[k2] = -1;
					}
				}
			}
			k++;
		}
		for (int j = 1; j <= n; j++) {
			if (a2[j] != -1) {
				b[a2[j]]++;

			}
		}
		x++;
		k = 1;
		cout << endl;
		for (int j = 1 ; j <= n; j++) {
			a2[j] = -1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}



	return 0;
}