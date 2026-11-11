#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m;
	if ( m > n) {
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	cout << max{a};
	return 0;
}