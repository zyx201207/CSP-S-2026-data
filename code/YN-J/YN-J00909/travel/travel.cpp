#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string Rc, Rz, Xc, Xz;

bool pd1(string a, string b) {
	if (a == b)
		return true;
	return  false;
}

bool pd2(string a, string b) {
	if (a[0] == b[0] && a[1] == b[1])
		return true;
	return false;
}

bool pd3(string a, string b) {
	if (a[2] == 'A' && (b[2] == 'B' || b[2] == 'C'))
		return true;
	if (a[2] == 'B' && (b[2] == 'A' || b[2] == 'C'))
		return true;
	if (a[2] == 'C' && (b[2] == 'A' || b[2] == 'B'))
		return true;
	if (a[2] == 'D' && b[2] == 'F')
		return true;
	if (a[2] == 'F' && b[2] == 'D')
		return true;
	return false;
}

bool pd4(string a, string b) {
	if (abs(a[2] - b[2]) == 1) {
		if (a[2] <= 'C' && b[2] <= 'C') {
			return true;
		} else {
			return false;
		}
	} else {
		if (a[2] >= 'D' && b[2] >= 'D') {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> Rc >> Rz >> Xc >> Xz;

	if (pd1(Rc, Xc)) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (pd1(Rc, Xc) && pd2(Rz, Xz)) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (pd1(Rc, Xc) && pd2(Rz, Xz) && pd3(Rz, Xz)) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (pd1(Rc, Xc) && pd2(Rz, Xz) && pd3(Rz, Xz) && pd4(Rz, Xz)) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}