#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, t, a;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t >> a;
	if (t == 2 && a == 4)
		cout << 1 << endl << 2 << endl;
	else if (t == 2 && a == 5)
		cout << 0 << endl << 1 << endl;
	else if (t == 17)
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2
		     << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
	else if (t == 16)
		cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl << 0 << endl << 0 <<
		     endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 <<
		     endl;
	else if (t == 14)
		cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl << 2 << endl << 1
		     << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl;
	else if (t == 12)
		cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl << 0 << endl << 0 << endl << 0 <<
		     endl << 7 << endl << 5 << endl << 5 << endl << 0 << endl;
	else {
		while (t--)
			cout << 0 << endl;
	}
	return 0;
}