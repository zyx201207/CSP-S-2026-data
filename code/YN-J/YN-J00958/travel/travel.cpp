#include <bits/stdc++.h>
using namespace std;
const int N = 25;
string  c[N];
char a[N], s[N], d[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> c[i];
		if (i == 1) {
			for (int j = 1; j <= 3; j++)
				cin >> s[j];
		} else {
			for (int j = 1; j <= 3; j++)
				cin >> a[j];
		}
	}
	if (c[1] == c[2]) {
		int cnt = 0;
		d[1] = '1';
		for (int i = 1; i <= 2; i++) {
			if (a[i] == s[i])
				cnt++;
		}
		if (cnt == 2) {
			d[2] = '1';
			if ((s[3] == 'D' && a[3] == 'F') || (s[3] == 'D' && a[3] == 'F')) {
				d[3] = '1';
				d[4] = '1';
			} else if ((s[3] == 'A' && a[3] == 'B') || (s[3] == 'B' && a[3] == 'A') || (s[3] == 'A' && a[3] == 'C') || (s[3] == 'C'
			           && a[3] == 'A') || (s[3] == 'B' && a[3] == 'C') || (s[3] == 'C' && a[3] == 'B')) {
				d[3] = '1';
				if ((s[3] == 'A' && a[3] == 'B') || (s[3] == 'B' && a[3] == 'A') || (s[3] == 'B' && a[3] == 'C') || (s[3] == 'C'
				        && a[3] == 'B'))
					d[4] = '1';
				else
					d[4] = '0';
			} else if ((s[3] == 'D' && a[3] == 'C') || (s[3] == 'C' && a[3] == 'D')) {
				d[3] = '0';
				d[4] = '0';
			}
		}

		else {
			for (int i = 2; i <= 4; i++)
				d[i] = '0';

		}



	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 1; i <= 4; i++)
		cout << d[i];


	return 0;
}