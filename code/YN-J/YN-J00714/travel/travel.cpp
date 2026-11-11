#include <bits\stdc++.h>
using namespace std;

struct d {
	int a, p;
	char b;
} s[3];
int n = 67, x = 68, m = 65;

int  main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> s[i].a >> s[i].p >> s[i].b;
	}

	for (int i = 1; i <= 1; i++) {
		if (s[i].a == s[i + 1].a) {
			if (s[i].p == s[i + 1].p) {
				if ( s[i].b != m && s[i + 1].b != n ) {
					if ( s[i].b != n && s[i + 1].b != m) {
						if ( s[i].b != n && s[i + 1].b != x  ) {
							if (s[i].b != x && s[i + 1].b != n) {



								if (s[i].b == s[i + 1].b - 1 || s[i].b - 1 == s[i + 1].b) {
									cout << "1111";
								} 	else {
									cout << "1110";
								}
							} else {
								cout << "1100";
							}
						} else {
							cout << "1100";
						}
					} else {
						cout << "1110";
					}

				} else {
					cout << "1110";
				}
			} else {
				cout << "1000";
			}
		} else {
			cout << "0000";
		}
	}


	return 0;
}