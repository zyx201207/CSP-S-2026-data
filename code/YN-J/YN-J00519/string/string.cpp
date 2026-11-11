#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[10086];
char c[10086];
string s;

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		cin >> c[i];
	}
//	if(n == 1) {
//		cout << 0;
//	} else if(n == 2) {
//		if(a[1] == a[2]) {
//			cout << 0;
//		} else {
//			cout << 1;
//		}
//	} else if(n == 3) {
//		if(a[1] == a[3]) {
//			cout << 0;
//		} else {
//			cout << 1;
//		}
//	} else if(n == 4) {
//		if(a[1] == a[4]) {
//			cout << 0;
//		}
//	}
//
//
	for (int i = 1; i <= 1000; i++) {
		if (n == i) {
			if (a[1] == a[i]) {
				cout << 0;
				break;
			} else {
				if (n <= 3) {
					cout << 1;
					break;
				} else {
					if (n == 4) {
						if (a[2] == a[3]) {
							cout << 1;
						} else {
							cout << 2;
						}
					} else if (n == 5) {
						if (a[2] == a[5]) {
							cout << 1;
						} else {
							cout << 2;
						}
					} else if (n == 6) {
						if (a[2] == a[5]) {
							if (a[3] == a[4]) {
								cout << 1;
							} else {
								cout << 2;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
