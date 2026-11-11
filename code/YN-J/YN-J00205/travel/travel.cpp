#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	string ans = "";
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000";
		return 0;
	};
	ans += "1";
	int r, q, rr, qq;
	/*
	rr = b[0];
	qq = d[0];
	r = b[1];
	q = d[1];
	if (rr == 1)
		r += 10;
	if (qq == 1)
		q += 10;
	cout << rr << " " << r << endl;
	cout << qq << endl;
	cout << r << q << endl;
	if (r == q)
		ans += "1";
	else {
		cout << "1000";
		return 0;
	}
	*/
	if (b[0] * 10 + b[1] == d[0] * 10 + d[1])
		ans += "1";
	else {
		cout << "1000";
		return 0;
	}
	char r2, q2;
	r2 = b[2];
	q2 = d[2];
	if (((r2 >= 'A' && r2 <= 'C' ) && ( q2 >= 'A' && q2 <= 'C')) || ((r2 >= 'D' && r2 <= 'F' ) && ( q2 >= 'D'
	        && q2 <= 'F'))) {
		ans += "1";
	} else {
		//cout << r2 << " " << q2 << endl;
		cout << "1100";
		return 0;
	}
	if ((r2 == 'F' && q2 == 'D') || (r2 == 'D' && r2 == 'F') || (r2 == 'C' && q2 == 'B') || (r2 == 'B' && q2 == 'C')
	        || (r2 == 'B' && q2 == 'A') || (r2 == 'A' && q2 == 'B')) {
		ans += "1";
	} else {
		cout << "1110";
		return 0;
	}
	cout << ans;
	return 0;
}