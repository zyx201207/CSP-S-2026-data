#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m, dy;
	string a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	for (int b = 1; b <= n; b++) {
		if (a[b] == b) {
			dy += 1;
			cout << dy ;
		}
	}
	return 0;
}