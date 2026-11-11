#include <bits/stdc++.h>
using namespace std;
int a[20000005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		if (a[i] == a[i + 1]) {
			cout << a[i];
		}
	}

	return 0;
}