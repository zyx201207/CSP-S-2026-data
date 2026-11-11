#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, ans[N], a[N], d[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		d[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		//memset(vis, sizeof(vis), 0);
		int j = i;
		while (j <= n) {
			ans[a[j]]++;
			j = d[a[j]] + 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld ", ans[i]);
	}
	cout << endl;
	return 0;
}