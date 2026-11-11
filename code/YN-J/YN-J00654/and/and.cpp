#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s, z = -1;
	for (int i = 0; i < n; i++) {
		s = a[i];
		for (int j = i; j < m; j++) {
			s = s & a[i + j];
		}
		if (s > z) {
			z = s;
		}
	}
	cout << z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}