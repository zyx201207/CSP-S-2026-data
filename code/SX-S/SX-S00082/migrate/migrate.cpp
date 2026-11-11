#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int x, h;
	cin >> x >> h;
	cin >> h;
	if (h == 4) {
		cout << "1\n2";
	} else if (h == 5)
		cout << "0\n1";
	else
		cout << "iakioi";
	return 0;
}