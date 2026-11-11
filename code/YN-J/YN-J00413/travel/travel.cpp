#include  <bits/stdc++.h>
using namespace std;

int mian() {
	int c1, s1, c2, s2, n;
	cin >> c1 >> s1 >> c2 >> s2;
	char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
	vecter<int> vec;
	for (int i = 1; i <= 17; ++i) {
		for (int j = 1; j <= 18; ++j) {
			for (int k = 1; k <= 5; ++k) {
				if (c1 == c2) {
					cout << "1";
				} else {
					cout << "0";
				}
				continue;
				if (s1 == s2) {
					cout << "1";
				} else {
					cout << "0";
				}
				continue;
				if (vec[n] == a || vec[n] == b || vec[n] == c) {
					cout << "1";
				} else if (vec[n] == d || vec[n] == e) {
					cout << "1";
				} else {
					cout << "0";
				}
				continue;
				if (vec[n - 1] == a || vec[n + 1] == c) {
					cout << "1";
				} else if (vec[n + 1] == b || vec[n + 1] == c) {
					cout << "1";
				} else if (vec[n + 1] == a || vec[n - 1] == d) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
		}
	}
	return 0;
}