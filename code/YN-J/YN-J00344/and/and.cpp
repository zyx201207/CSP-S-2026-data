#include <bits/stdc++.h>
using namespace std;
int n, m, s[200005], ax, z, k;

int main() {
	freopen("and.in", 'r', stdin);
	freopen("and.out", 'w', stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> s[i];
	}

	for (int i = 0; i < m; i++) {

		ax = 0, z = 0;

		for (int j = 0; j < n; j++) {

			if (s[j] > ax) {
				ax = s[j];
				z = j;
			}
		}

		k = s[z];
		s[z] = 0;
	}

	cout << k;
	return 0;
}