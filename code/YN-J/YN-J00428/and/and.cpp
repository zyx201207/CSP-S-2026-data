#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], b, mina = 10000000;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (a[i] < mina) {
			mina = a[i];
		}
	}

	cout << mina;
	return 0;
}
