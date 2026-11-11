#include <bits/stdc++.h>
using namespace std;

int a, c;
string b, d;

int main () {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		int id = (b[0] - '0') * 10 + b[1] - '0';
		int id2 = (d[0] - '0') * 10 + d[1] - '0';
		if (id == id2) {
			cout << "1";
			if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) {
				cout << "1";
				int tmp = b[2] - d[2];
				if (tmp == 1 || tmp == -1) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
