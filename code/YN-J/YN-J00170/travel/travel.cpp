#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int n1 = 0, n2 = 0;

	for (int i = 0; i <= 1; i++) {

		n1 += s1[i] - '0';
	}

	for (int i = 0; i <= 1; i++) {

		n2 += s2[i] - '0';
	}

	int m1 = s1[2] - 'A' + 1, m2 = s2[2] - 'A' + 1;
	int t1 = 0, t2 = 0;

	if (m1 == 4 || m1 == 5)
		t1 = 1;
	else
		t1 = 2;

	if (m2 == 4 || m2 == 5)
		t2 = 1;
	else
		t2 = 2;

	if (c1 == c2)
		cout << "1";
	else {
		cout << "0000";
		return 0;
	}


	if (n1 == n2)
		cout << "1";
	else {
		cout << "000";
		return 0;
	}

	if (t1 == t2)
		cout << "1";
	else {
		cout << "00";
		return 0;
	}

	if (abs(m1 - m2) != 1) {
		cout << "0";
		return 0;
	}

	cout << "1";




	return 0;
}




