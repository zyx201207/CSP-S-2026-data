#include <bits/stdc++.h>
using namespace std;
int c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int n, k, ans;
	cin >> c >> t >> n >> k;
	for (int i = 0; i <= n; i++) {
		ans++;
		n = c + t;
		for (int j = 0; j <= n; j++) {
			ans += 2;
			k = c * t;
		}
	}
	cout << n << " " << k;
	return 0;
	fclose(stdin);
	fclose(stdout);
}