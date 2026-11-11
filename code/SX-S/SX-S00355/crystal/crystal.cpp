#include <bits/stdc++.h>
using namespace std;
int n, m, d, z, a;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int w[n - 1], q[n - 1], s[n - 1];
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (q[i] >= q[j])
				w[j] = q[i] - q[j];
			else
				w[j] = -1;
		}
		d = m;
		for (int j = 0; j < n; j++) {
			if (d - w[j] >= 0 && w[j] != -1) {
				d -= w[j];
				a += 1;
			}
		}
		s[i] = a;
		a = 0;
		memset(w, 0, sizeof(w));
	}
	for (int i = 0; i < n; i++) {
		z = max(s[i], z);
	}
	cout << z;
	return 0;
}
