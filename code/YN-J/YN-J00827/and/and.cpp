#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	const int N = n;
	int a[N];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxx = -1;
	for (int i = 0; i < n ; i++) {
		int s = a[i];
		for (int j = 0; j <  m; j++) {
			s &= a[i + j + 1];
		}
		if (maxx < s) {
			maxx = s;
		}
	}
	cout << maxx;
	return 0;
}