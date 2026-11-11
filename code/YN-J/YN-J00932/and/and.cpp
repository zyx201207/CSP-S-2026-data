#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, d1 = 0, d2 = 0;
	string l;
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l;
	}
	for (int i = 0; i < n; i++) {
		if (d1 < l[i]) {
			d1 = l[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (d2 < l[i]) {
			d2 = l[i];
			if (d2 == d1) {
				continue;
			}
		}
	}
	count = d2;
	return 0;
}