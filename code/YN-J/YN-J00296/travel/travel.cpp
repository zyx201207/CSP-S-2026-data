#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string num1, num2;
	string a1, a2;
	a1 += s1[2];
	a2 += s2[2];

	for (int i = 0; i < 2; i++) {

		num1 += s1[i];
		num2 += s2[i];
	}

	if (c1 == c2) {
		cout << 1 ;

		if (num1 == num2) {
			cout << 1 ;

			if (a1 == "A" || a1 == "B" || a1 == "C") {
				if (a2 == "A" || a2 == "B" || a2 == "C") {
					cout << 1;

					if (a1 == "A" && a2 == "C") {
						cout << 0;
					}

					if (a2 == "A" && a1 == "C") {
						cout << 0;
					} else {
						cout << 1;
					}
				}

				if (a2 == "D" || a2 == "F") {
					cout << 0 <<  0;
				}
			}

			if (a1 == "D" || a1 == "F") {
				if (a2 == "D" || a2 == "F") {
					cout << 11;
				}

				if (a2 == "A" || a2 == "B" || a2 == "C") {
					cout << 0 << 0;
				}
			}
		} else {
			cout << 0 << 0 << 0;
		}

	} else {
		cout << 0 << 0 << 0 << 0;
	}



	return 0;
}