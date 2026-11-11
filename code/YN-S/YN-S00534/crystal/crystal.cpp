#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m, d;
	cin >> n >> m;
	string a;
	d = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	for (int b = 1; b <= n; b++) {
		d = a[b] + 1;
		cout << d;
	}
	return 0;
}