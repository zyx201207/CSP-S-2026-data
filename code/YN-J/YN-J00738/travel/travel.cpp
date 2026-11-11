#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int flag;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string a, b;
	a = s1[0] + s1[1];
	b = s2[0] + s2[1];
	if (c1 == c2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (a == b)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (s1[2] < 'D' && s2[2] < 'D') {
		cout << 1;
		flag = 1;
	} else if (s1[2] > 'D' && s2[2] > 'D') {
		cout << 1;
		flag = 2;
	} else {
		cout << 0;
		flag = 3;
	}
	if (flag == 1 && abs(s1[2] - s2[2]) == 1)
		cout << 1;
	else if (flag == 2)
		cout << 1;
	else
		cout << 0;
	return 0;
}