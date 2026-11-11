#include<bits/stdc++.h>
using namespace std;
int ac, bc, ap, bp;
char a, b, c;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ac >> c; ap = (int)(c - 48);
	cin >> c >> a; ap = ap * 10 + (int)(c - 48);
	cin >> bc >> c; bp = c - 48;
	cin >> c >> b; bp = bp * 10 + c - 48;
	if (ac == bc) {
		cout << 1;
		if (ap == bp) {
			cout << 1;
			if (a == 'A' || a == 'B' || a == 'C') {
				if (b == 'A' || b == 'B' || b == 'C') {
					cout << 1;
					if (a == 'A' && b == 'C' || a == 'C' && b == 'A') cout << 0;
					else cout << 1;
				} else cout << "00";
			} else if (b == 'D' || b == 'F') cout << "11";
			else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}