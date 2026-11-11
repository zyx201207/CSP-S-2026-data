#include <bits/stdc++.h>
using namespace std;
int n, m, w;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int a[n];
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		int s = a[i] and a[i - 1];
		if (s > w) {
			w = s;
		}
	}
	cout << w;

	return 0;
}
