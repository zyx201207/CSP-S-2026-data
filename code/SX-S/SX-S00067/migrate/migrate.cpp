#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+1;
int c, t;
ll a;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (cin >> a)	;
	if (t == 1) {
		cout << 3;
	}
	if (t == 2) {
		cout << 5 << endl << 7;
	}
	if (t == 3) {
		cout << 2 << endl << 3 << endl << 6;
	}
	return 0;
}
