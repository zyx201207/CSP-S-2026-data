#include <bits/stdc++.h>
using namespace std;
int n, m, a[20005], MAX = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		MAX = max(MAX, a[i]);
	}
	cout << MAX;
	return 0;
}