#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 != c2) {
		cout << "0000";
		return 0;
	}

	cout << 1;
	string b1, b2;
	b1 = s1.substr(0, 2);
	b2 = s2.substr(0, 2);
	int flag = 0, sa = s1.size(), sb = s2.size();

	if (b1 == b2)
		cout << 1, flag++;
	else {
		cout << "000";
		return 0;
	}


	if (float(s1[sa - 1] - 'C' - 0.5)*float(s2[sb - 1] - 'C' - 0.5) >= 0) {
		cout << 1;

		if (abs(s1[sa - 1] - s2[sb - 1]) == 1)
			flag++;
	} else
		cout << 0;

	if (flag >= 2)
		cout << 1;
	else
		cout << 0;

	return 0;
}