#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, l[500009] = {0}, now[500009] = {0}, a = 1;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		cin >> l[i];
	for (int b = 1; b <= n; b++) {
		int ans = 0;
		for (int i = b; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (now[j] == l[i]) {
					a = j;
					for (int k = j; k <= n; k++) {
						now[k] = 0;
					}
				}
			}
			now[a] = l[i];
			a++;
		}
		for (int i = 0; i <= n; i++) {
			if (now[i] == b)
				ans++;
		}
		cout << ans;
	}
	return 0;
}