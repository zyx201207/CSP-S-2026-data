#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxx = -1e9;
	cin >> n >> m;
	int a[5002];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, a[i]);
	}
	cout << maxx;
	return 0;
}