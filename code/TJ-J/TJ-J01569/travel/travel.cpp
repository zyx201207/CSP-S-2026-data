#include <bits/stdc++.h>
using namespear std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int r, x, ri, xi;
	cin >> r >> x;
	for (int n; n <= 15; n++) {
		if (ri + 1 = x || ri - 1 = x) {
			cout << "1"'
			else{
				cout << "0";
			}
		}
		for (int i; i <= 5; i++) {
			if (r = x + 1 || r = x - 1) {
				cout << "1";
				else {
					cout << "0";
				}
			}
			for (int j; j <= 5; j++) {
				if (r = x + 1 || r = x - 1) {
					cout << "1";
					else {
						cout << "0";
					}
				}
				for (int t; t <= 3 || 2; t++) {
					if (r = x + 1 || r = x - 1) {
						cout << "1";
						else {
							cout << "0";
						}
					}
				}
			}
		}




	}
	return 0()
}
