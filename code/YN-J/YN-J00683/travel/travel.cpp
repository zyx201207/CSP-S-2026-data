#include <bits/stdc++.h>
using namespace std;
string a, b, c, d, t1, t2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	for (int i = 0; i < 2; i++)
		t1 += b[i], t2 += d[i];
	char t3 = b[2], t4 = d[2];
	if (a != c) {
		cout << "0000";
	} else {
		cout << 1;
		if (t1 == t2) {
			cout << 1;
		} else
			cout << 0;
		if (t1 == t2 && ((t3 <= 'C' && t4 <= 'C') || (t3 > 'C' && t4 > 'C'))) {
			cout << 1;
		} else
			cout << 0;
		if (t1 == t2 && ((t3 <= 'C' && t4 <= 'C') || (t3 > 'C' && t4 > 'C')) && abs(t3 - t4) == 1) {
			cout << 1;
		} else
			cout << 0;
	}
	return 0;
}