#include <bits/stdc++.h>
using namespace std;

int T(string a) {
	return (a[0] - '0') * 10 + (a[1] - '0');
}

bool A(char A, char B) {
	int a = int(A), b = int(B);
	if (max(a, b) <= int('C') || min(a, b) >= int('D'))
		return true;
	return false;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("trsvel.out","w",stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int t1 = T(a), t2 = T(c);
	int s1 = T(b), s2 = T(d);
	if (t1 == t2) {
		cout << 1;
		if (s1 == s2) {
			cout << 1;
			if (A(b[2], d[2])) {
				cout << 1;
				if (abs(b[2] - d[2]) == 1) {
					cout << 1;
				} else
					cout << "0";
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}