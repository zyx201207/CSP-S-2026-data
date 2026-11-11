#include <bits/stdc++.h>
using namespace std;
int n, a[200003], m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int max1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		max1 = max(max1, a[i]);
	}
	cout << max1;
	return 0;
}