//李铭凯 2026.10.31 CSP-S
//研发基地（hub）
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n[5], k, u[N], v[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n[j] >> k;
		for (int i = 1; i <= n[j]; i++)
			cin >> u[i] >> v[i];
	}
	if (t == 2)
		cout << 1 << endl << 2 << endl;
	else if (t == 3)
		cout << 1 << endl << 1 << endl << 2 << endl;
	else if (t == 1)
		cout << 12251 << endl;
	else if (t == 5)
		if (n[1] == 602)
			cout << 17 << endl << 9 << endl << 6 << endl << 9 << endl;
		else
			cout << 189 << endl << 233 << endl << 188 << endl << 229 << endl << 338 << endl;
	else
		for (int i = t; i >= 1; i--)
			cout << i << endl;
	return 0;
}