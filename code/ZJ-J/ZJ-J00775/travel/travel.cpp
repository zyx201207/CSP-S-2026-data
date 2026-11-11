#include <bits/stdc++.h>
using namespace std;

string s1, s2;
char c1, c2, s[10];
int a1, a2, sum;

int init () {
	sum = 0;
	cin >> s[0] >> s[1];
	for (int i = 0; i <= 1; i++)
		sum = sum * 10 + (s[i] - '0');
	return sum;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1;
	a1 = init ();
	cin >> c1;
	cin >> s2;
	a2 = init ();
	cin >> c2;
//	cout << s1 << " " << a1 << " " << c1 << "\n";
//	cout << s2 << " " << a2 << " " << c2 << "\n";
	if (s1 == s2) {
		cout << "1";
		if (a1 == a2) {
			cout << "1";
			if ((c1 <= 'C') == (c2 <= 'C')) {
				cout << "1";
				int n1 = int (c1), n2 = int (c2);
//				cout << n1 << " " << n2 << "\n";
				if (max (n1, n2) - min (n1, n2) == 1)
					cout << "1";
				else
					cout << "0";
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
}