#include <bits/stdc++.H>
using namespace std;

struct pat {
	string a;
	string c;
	char b;
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	pat r, x;
	cin >> r.a >> r.c;
	cin >> x.a >> x.c;
	if (r.a[0] == x.a[0] && r.a[1] == x.a[1])
		cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	r.b = r.c[2];
	x.b = x.c[2];
	if (r.c[0] == x.c[0] && r.c[1] == x.c[1])
		cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if (r.b >= 'A' && r.b <= 'C' && x.b >= 'A' && x.b <= 'C')
		cout << "1";
	else if (r.b >= 'D' && r.b <= 'F' && x.b >= 'D' && x.b <= 'F')
		cout << "11";
	else {
		cout << "00";
		return 0;
	}
	if (r.b == x.b + 1 || r.b == x.b - 1)
		cout << "1";
	else
		cout << "0";
	return 0;
}