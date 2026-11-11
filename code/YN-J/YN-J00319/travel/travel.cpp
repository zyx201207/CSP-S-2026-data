#include <bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;


bool f = true;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> c1 >> s2 >> c2;
	int a = (c1[0] - '0') * 10 + (c1[1] - '0');
	int b = (c2[0] - '0') * 10 + (c2[1] - '0');
	int c = c1[2];
	int d = c2[2];
	int q = abs(c - d);
	if (s1 == s2 && s1 != "01" && s1 != "16") {
		cout << 1;
		f = false;
	} else {

		cout << 0;
	}

	if (a == b && f == false) {


		cout << 1;

		if (c <= 'C' && d <= 'C') {
			cout << 1;
			if (q == 1) {

				cout << 1;
			} else {

				cout << 0;
			}
		} else if (c > 'C' && d > 'C') {
			cout << 1 << 1;
		} else{
			cout << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0;
	}
	return 0;
}