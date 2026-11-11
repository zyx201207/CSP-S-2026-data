#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n, t, num, m, a;
	cin >> n >> t;
	while (t--) {
		cin >> num >> m;
		for (int i = 1; i <= num; i++) {
			cin >> a;
		}
		int b = num - 2 * m + 1;
		if (b <= 0 )
			cout << 0 << endl;
		else
			cout << b << endl;
	}
	return 0;
}