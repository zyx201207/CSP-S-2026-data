#include <bits/stdc++.h>
using namespace std;
int x[10000000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> x[i];
	}

	sort(x + 1, x + n + 1);
	cout << x[(n + 1) / 2];
	return 0
	       ;
}