#include <bits/stdc++.h>
using namespace std;
freopen("and.in""r""stdin");
freopen("and.out""w""stdout");

int main () {
	int n, m, a[100005] = {0};
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, snm = 0;
	for (int i = 1; i <= nm; i++) {
		for (int j = 1; j <= m; j++) {
			sum ^= a[j];
		}
		if (sum >= snm) {
			snm = sum;
			sum = 0;
		} else {
			sum = 0;
		}
	}
	cout << snm;


	return 0;
}