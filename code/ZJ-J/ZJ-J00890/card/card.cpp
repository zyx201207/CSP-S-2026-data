#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxm = 3005;
int on, n, m, a[maxn], nouse[maxn], use[maxm], ans[maxm], lst[maxm];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m; on = n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= on; i++) {
		for (int j = 1; j <= n; j++)
			nouse[j] = 0;
		for (int j = 1; j <= m; j++)
			lst[j] = use[j] = 0;
		for (int j = 1; j <= n; j++) {
			if (lst[a[j]] && !nouse[lst[a[j]]])
				for (int k = lst[a[j]]; k < j; k++)
					nouse[k] = 1;
			lst[a[j]] = j;
		}
		for (int j = 1; j <= n; j++)
			if (!nouse[j])
				use[a[j]] = 1;
		for (int j = 1; j <= m; j++)
			ans[j] += use[j];
		for (int j = 2; j <= n; j++)
			a[j - 1] = a[j];
		n--;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
}