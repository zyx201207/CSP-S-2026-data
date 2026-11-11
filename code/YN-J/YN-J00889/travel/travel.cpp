#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a, b, c, d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("travel.in", "r", stdin);

	freopen("travel.out", "w", stdout);

	cin >> a >> b >> c >> d;
	char t1, t2;
	t1 = b[2];
	t2 = d[2];
	ll n1, n2;
	n1 = b[1] - '0';
	if (b[0] == '1') {
		n1 += 10;
	}
	n2 = d[1] - '0';
	if (d[0] == '1') {
		n2 += 10;
	}
	if (a == c) {
		cout << 1;
		if (n1 == n2) {
			cout << 1;
			if (t1 <= 'C' && t2 <= 'C' || t1 >= 'D' && t2 >= 'D') {
				cout << 1;
			} else {
				cout << 0;
			}
			if (t1 == 'A' && t2 == 'B' || t1 == 'B' && t2 == 'A'
			        || t1 == 'B' && t2 == 'C' || t1 == 'C' && t2 == 'B'
			        || t1 == 'D' && t2 == 'E' || t1 == 'E' && t2 == 'D') {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
			cout << 0;
			cout << 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	//cout << endl << t1 << " " << t2 << endl;


//02 01A 02 01B

	return 0;
}