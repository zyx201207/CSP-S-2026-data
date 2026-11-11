#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen('travel.in', 'r', stdin);
	freopen('travel.out', 'w', stdout);
	int c1, s1, c2, s2;
	cin >> c1, s1, c2, s2;
	int isalpha1(int s1);
	int isalpha2(int s2);

	if (c1 == c2 ) {
		cout << '1' << endl;
	} else {
		cout << '0' << endl;
	}

	if (s1 == s2) {
		cout << '1' << endl;
	} else {
		cout << '0' << endl;
	}

	return 0;
}
