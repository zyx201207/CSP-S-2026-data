#include <bits\stdc++.h>
using namespace std;

int n;
string a[10000001];
int  main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "0";
	}
	if (n == 2 && a[1] == a[2]) {
		cout << "0";
	} else {
		cout << "1";
	}
	if (n == 3 && a[1] == a[2]) {
		cout << "0";
	} else if (a[1] == a[2] || a[2] == a[3] || a[1] == a[3]) {
		cout << "1";
	}

	return 0;
}