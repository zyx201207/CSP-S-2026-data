#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
void query () {
	string a1 = s1.substr(0, 2);
	string a2 = s2.substr(0, 2);
	if (c1 == c2) cout << 1;
	else {
		cout << "0000";
		return ;
	}
	if (a1 == a2) cout << 1;
	else {
		cout << "000";
		return ;
	}
	char ch1 = s1[2];
	char ch2 = s2[2];
	bool f = 0;
	if ((ch1 == 'A' || ch1 == 'B' || ch1 == 'C') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C'))
		f = 1;
	if ((ch1 == 'D' || ch1 == 'F') && (ch2 == 'D' || ch2 == 'F'))
		f = 1;
	if (f == 1) cout << 1;
	else {
		cout << "00";
		return ;
	}
	if (ch1 > ch2) swap(ch1, ch2);
	f = 0;
	if (ch1 == 'A' && ch2 == 'B' || ch1 == 'B' && ch2 == 'C' || ch1 == 'D' && ch2 == 'F')
		cout << 1;
	else cout << 0;
	return ;
}
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	query ();
	return 0;
}