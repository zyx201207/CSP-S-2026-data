#include <bits/stdc++.h>
using namespace std;
int a, c;
string b, d;
bool check(char& ch) {
	return (ch >= 'A' && ch <= 'C');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		int t1 = (b[0] - '0') * 10 + b[1] - '0';
		int t2 = (d[0] - '0') * 10 + d[1] - '0';
		if (t1 == t2) {
			cout << 1;
			if (check(b[2]) == check(d[2])) {
				cout << 1 << (b[2] == d[2] + 1 || b[2] == d[2] - 1);
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
