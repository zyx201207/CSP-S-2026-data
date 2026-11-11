#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m, s, t;
	string a, b;
	cin >> n >> a >> m >> b;
	if (n != m) {
		cout << "0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	char c, d;
	if (a.size() == 2) {
		s = a[0] - '0';
		c = (char) a[1];
	} else {
		s = a[1] - '0' + (a[0] - '0') * 10;
		c = (char) a[2];
	}
	if (b.size() == 2) {
		t = b[0] - '0';
		d = (char) b[1];
	} else {
		t = b[1] - '0' + (b[0] - '0') * 10;
		d = (char) b[2];
	}
	//cout << c << ' ' << d << endl;
	if (s != t) {
		cout << "1000" << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if ((c < 'D' && d > 'C') ||(c > 'C' && d < 'D')){
		cout << "1100" << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (abs((c - 'A') - (d - 'A')) > 1) {
		if (!(c == 'D' && d == 'F')||(c == 'F' && d == 'D')) {
			cout << "1110" << endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	cout << "1111" << endl;
	return 0;
}
