#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], t[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i > 0; i--)
		if (!t[a[i]])
			t[a[i]]++, ans[a[i]] = i;
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}