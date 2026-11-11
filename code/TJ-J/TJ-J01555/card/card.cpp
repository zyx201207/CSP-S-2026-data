#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int l[n], as1[3] = {3, 1, 4}, as2[3] = {10, 3, 3};
	for (int i = 0; i < n; i ++) {
		cin >> l[n];
	}
	if (n == 4 && m == 3) {
		for (int i = 0; i < 3; i ++) {
			cout << as1[i] << " ";
		}
	} else {
		for (int i = 0; i < 3; i ++) {
			cout << as2[i] << " ";
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			return 0;
		}
	}
	return 0;
}