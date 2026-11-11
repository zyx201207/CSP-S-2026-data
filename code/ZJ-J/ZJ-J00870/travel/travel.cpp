#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
string a, b;
bool checkA(string x, string y) {
	char c1 = x[2], c2 = y[2];
	if (c1 <= 'C' && c1 >= 'A' && c2 <= 'C' && c2 >= 'A') {
		return true;
	}
	return false;
}
bool checkD(string x, string y) {
	char c1 = x[2], c2 = y[2];
	if (c1 <= 'F' && c1 >= 'D' && c2 <= 'F' && c2 >= 'D') {
		return true;
	}
	return false;
}
bool checkT(string x, string y) {
	char c1 = x[2], c2 = y[2];
	if (checkA(x, y)) {
		if (c1 == 'B' || c2 == 'B') return true;
		else return false;
	}
	return true;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;
	cin >> a;
	cin >> m;
	cin >> b;
	if (n == m) {
		cout << "1";
		if (a[0] == b[0] && a[1] == b[1]) {
			cout << "1";
			if (checkA(a, b) || checkD(a, b)) {
				cout << "1";
				if (checkT(a, b)) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
