//T1
#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> a >> d >> b;
	if (c == d) {
		cout << 1;
		ans++;
		if (a[0] == b[0] && a[1] == b[1]) {
			cout << 1;
			ans++;
			if ((a[2] <= 'C' && b[2] <= 'C') || (a[2] > 'C' && b[2] > 'C')) {
				cout << 1;
				ans++;
				if (abs(a[2] - b[2]) <= 1) {
					ans++;
					cout << 1;
				}
			}
		}
	}
	for (int i = ans; i <= 3; i++) {
		cout << 0;
	}
	return 0;
}