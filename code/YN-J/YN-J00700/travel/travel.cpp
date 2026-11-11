#include <bits/stdc++.h>
using namespace std;
string ca[25], cb[25], sa[105], sb[105];
string aa = "A", ab = "B", ac = "C", ad = "D", ae = "E";

int chx(string x, string y) {
	if (x != y) {
		return 0;
	}
	return 1;
}

int typ(string a, string b) {
	if (chx(a, b) == 0) {
		a = a.erase(2);
		b = b.erase(2);
		//cout << a << " " << b;
		if (a == b)
			return 1;
		else
			return 0;
	} else {
		return 0;
	}
}

int tyc(string a, string b) {
	if (typ(a, b) == 1) {
		a = a.erase(0, 2);
		b = b.erase(0, 2);
		//cout << " " << a << " " << b;
		if (a >= aa && a <= ac && b >= aa && b <= ac || a >= ad && a <= ae && b >= ad && b <= ae) {
			return 1;
		} else {
			return 0;
		}
	}

}

int xl(string a, string b) {
	if (tyc(a, b) == 1) {
		a = a.erase(0, 2);
		b = b.erase(0, 2);
		if (a == aa && b == ab || a == ab && b == ac || a == ad && a == ae) {
			return 1;
		}	else {
			return 0;
		}
	} else {
		return 0;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travl.in", "r", stdin);
	freopen("travl.out", "w", stdout);
	string ca, cb, sa, sb;
	cin >> ca >> sa >> cb >> sb;
	cout << chx(ca, cb);
	if (chx(ca, cb) == 0) {
		cout << "000";
	} else {
		cout << typ(sa, sb);
		if (typ(sa, sb) == 0) {
			cout << "00";
		} else {
			cout << tyc(sa, sb);
			if (tyc(sa, sb) == 0) {
				cout << "0";
			} else {
				cout << xl(sa, sb);
			}
		}


	}
	return 0;
}
