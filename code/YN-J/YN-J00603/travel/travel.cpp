#include <bits/stdc++.h>
using namespace std;

int main( ) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, h = 1, n = 1;
	char c2[5], s2[5];
	cin >> c1 >> c2 >> s1  >> s2;

	if (c1 == s1) {
		cout << h;
	} else {
		h = 0;
		cout << h;

	}

	if (c2[0] == s2[0] && c2[1] == s2[1]) {
		cout << h;
	} else {
		h = 0;
		cout << h;

	}

	if (c2[2] - 'A' <= 2  &&  s2[2] - 'A' <= 2 ) {

		cout << h;


	} else if (c2[2] - 'A' > 2 && s2[2] - 'A' > 2 ) {

		cout << h;
		cout << h;
		n = 0;
	} else {
		h = 0;
		cout << h;

	}



	if (c2[2] - 'A' <= 2  && s2[2] - 'A' <= 2 && c2[2] - s2[2] == 1 || s2[2] - c2[2] == 1) {

		cout << h;


	} else if (n == 1)
		cout << 0;






	return 0;
}