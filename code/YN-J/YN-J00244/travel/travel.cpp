#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3)
		cout << '1';
	else
		cout << '0';

	string t1 = s2.substr(0, 2), t2 = s4.substr(0, 2);
	if (s1 == s3 && t1 == t2)
		cout << '1';
	else
		cout << '0';

	char c1 = s2.back(), c2 = s4.back();
	if (s1 == s3 && t1 == t2 && c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C')
		cout << '1';
	else if (s1 == s3 && t1 == t2 && c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F')
		cout << '1';
	else
		cout << '0';

	if (s1 == s3 && t1 == t2 && ((c1 == 'C' && c2 == 'D') || (c1 == 'D' && c2 == 'C')))
		cout << '0';
	else if (s1 == s3 && t1 == t2 && c1 <= 'C' && c2 <= 'C' && abs(c1 - c2) == 1)
		cout << '1';
	else if (s1 == s3 && t1 == t2 && c1 <= 'F' && c2 <= 'F' && abs(c1 - c2) == 1)
		cout << '1';
	else
		cout << '0';
	return 0;
}