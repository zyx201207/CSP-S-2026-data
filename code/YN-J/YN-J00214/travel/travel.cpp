#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
string s;
int cnt;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	bool flg = 0;
	if (b[2] == 'D' || b[2] == 'C')
		cnt++;
	if (d[2] == 'D' || d[2] == 'C')
		cnt++;
	if (a == c) {
		s += "1";
		for (int i = 0; i <= 1; i++) {
			if (b[i] != d[i]) {
				s += "000";
				flg = 1;
			}
		}
		if (flg == 0) {
			s += "1";
			if (cnt < 2) {
				s += "1";
				if (abs(b[2] - d[2]) == 1)
					s += "1";
				else
					s += "0";
			} else {
				s += "00";
			}
		}

	} else {
		cout << "0000";
		return 0;
	}
	cout << s;
	return 0;
}
