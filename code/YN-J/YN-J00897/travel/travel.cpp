#include <bits/stdc++.h>
#define int long long
using namespace std;
string cc1, ss1, cc2, ss2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if (cc1 == cc2)
		cout << '1';
	else
		cout << '0';
	if (cc1 == cc2 && ss1[0] == ss2[0] && ss1[1] == ss2[1])
		cout << '1';
	else
		cout << '0';
	bool f = 0;
	if (cc1 == cc2 && ss1[0] == ss2[0] && ss1[1] == ss2[1]) {
		if ((ss1[2] <= 'C' && ss2[2] <= 'C') || (ss1[2] > 'C' && ss2[2] > 'C')) {
			f = 1;
			cout << '1';
		} else
			cout << '0';
	} else
		cout << '0';
	if (f == 1 && (char(ss1[2] + 1) == ss2[2] || char(ss1[2] - 1) == ss2[2]))
		cout << '1';
	else
		cout << '0';
	return 0;
}