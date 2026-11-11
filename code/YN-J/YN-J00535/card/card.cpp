#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int list_n[50005] = {};
	for (int i = 0; i < n; i++) {
		cin >> list_n[i];
	}

	int list_cs[50005] = {};

	for (int mn = 0; mn < n; mn++) {
		int list_p[50005] = {};
		int c = 0;
		for (int i = mn; i < n; i++) {
			for (int j = 0; j <= c; j++) {
				if (list_p[j] == list_n[i]) {
					for (int k = j; k < c; k++) {
						list_p[k] = 0;
					}
					c = j;
					break;
				}
			}
			list_p[c] = list_n[i];
			c++;
		}
		for (int i = 0; i < c; i++) {
			list_cs[list_p[i] - 1]++;
		}
	}
	for (int k = 0; k < m; k++) {
		cout << list_cs[k] << " ";
	}

	return 0;
}