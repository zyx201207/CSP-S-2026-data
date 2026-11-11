#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int a[N], ans[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ans[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';

	return 0;
} 
