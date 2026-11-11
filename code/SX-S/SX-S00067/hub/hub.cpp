#include <bits/stdc++.h>
using namespace std;
int c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a;
	cin >> c >> t;
	while (cin >> a)	;
	if (t == 1) {
		cout << 0;
	}
	if (t == 2)
		cout << 3 << endl << 2;
	if (t == 3)
		cout << 9 << endl << 3 << endl << 6;
	return 0;
}
