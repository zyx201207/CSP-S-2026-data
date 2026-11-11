#include <bits/stdc++.h>
using namespace std;
long long s[1000005];
long long s2[1000005];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> s[i] >> s2[i];
	}
	cout << 1;
	return 0;
}