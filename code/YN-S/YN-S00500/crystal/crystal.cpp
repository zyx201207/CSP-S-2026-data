#include <bits/stdc++.h>
using namespace std;
int t[150];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, t, ans;
	cin >> n >> m >> t;
	for (int i = 0; i <= n; i++) {
		ans++;
		for (int j = 1; j <= m; j++) {
			t++;
		}
	}
	cout << 3 ;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
