#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

string c1, s1, c2, s2, c3, s3;

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 == s1)
		cout << "1";

	else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i <= 1; i++) {
		c3 += c2[i];
		s3 += s2[i];
	}
	if (c3 == s3)
		cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if ((c2[2] >= 'D' && s2[2] >= 'D') || (c2[2] <= 'C' && s2[2] <= 'C'))
		cout << "1";
	else {
		cout << "00";
		return 0;
	}
	if (abs(c2[2] - s2[2]) == 1)
		cout << "1";
	else
		cout << "0";
	return 0;
}