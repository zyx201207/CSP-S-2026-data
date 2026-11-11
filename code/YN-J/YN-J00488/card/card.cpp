#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> k;
	srand(time(0));
	while (m--) {
		int x = (rand() + rand() + k) % 100;
		cout << x << ' ';
	}
	return 0;
}