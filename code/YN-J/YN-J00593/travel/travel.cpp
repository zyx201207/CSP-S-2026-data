#include <bits/stdc++.h>
using namespace std;

bool fun(char b, char d) {
	if (b == 'A' && (d == 'B' || d == 'C'))
		return true;
	else if (b == 'B' && (d == 'A' || d == 'C'))
		return true;
	else if (b == 'C' && (d == 'A' || d == 'B'))
		return true;
	else if ((b == 'F' && d == 'D') || (b == 'D' && d == 'F'))
		return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a == c)
		cout << 1;
	else
		cout << 0;

	if (a == c && b[0] == d[0] && b[1] == d[1])
		cout << 1;
	else
		cout << 0;

	if (a == c && b[0] == d[0] && b[1] == d[1] && fun(b[2], d[2]))
		cout << 1;
	else
		cout << 0;

	if (a == c && b[0] == d[0] && b[1] == d[1] && abs( b[2] - 'A' - (d[2] - 'A')) == 1 && (d[2] != 'C' && b[2] != 'D'
	        && d[2] != 'D'
	        && b[2] != 'C'))
		cout << 1;
	else
		cout << 0 ;
}