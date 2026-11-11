#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("travel.in", "t", stdin);
	freopen("travel.out", "w", stdout);
	double c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	for (int i = 1; i <= 4; i++) {
		if (c1 = c2)
			cout << "1";
		else
			cout << "0";
		if (s1 != s2)
			cout << "0";
		else
			cout << "1";

	}
	return 0;
}