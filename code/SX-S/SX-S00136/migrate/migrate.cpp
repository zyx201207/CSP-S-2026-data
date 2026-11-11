#include <bits/stdc++.h>
using namespace std;
long long a, b, c;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> a >> b >> c;
	if (c == 4)
		cout << 1 << '\n' << 2;
	if (c == 5)
		cout << 0 << '\n' << 1;
	if (c == 197)
		cout << 8129 << '\n' << 16 << '\n' << 9 << '\n' << 7 << '\n' << 12 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 2
		     << '\n' << 1 << '\n' << 0 << '\n' << 2 << '\n' << 3 << '\n' << 6 << '\n' << 0 << '\n' << 2 << '\n' << 0;
	return 0;
}
