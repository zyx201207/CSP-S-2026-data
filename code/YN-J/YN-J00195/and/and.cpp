#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	int n, m, maxa = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a > maxa) {
			maxa = a;
		}
	}
	cout << maxa;
	return 0;
}