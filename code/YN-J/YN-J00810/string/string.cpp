#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n, a;
	char c;
	int x = (n + 1) / 2;
	int cnt = 0;
	int i, j;
	cin >> n;

	for ( i = 1; i <= n; i++) {

		cin >> a >> c;
	}

	for ( j = i; j <= n; j++) {

		if ((x - 1) != (x + 1)) {
			cnt++;
			j++;
		} else {
			cout << 0;
		}
	}

	cout << cnt << endl;
	return 0;
}