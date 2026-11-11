#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 5e5 + 5, Maxm = 3e5 + 5;
int n, m, a[Maxn], cnt[Maxm], lst[Maxm], cards[Maxn], tot;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		tot = 0;
		for (int j = 1; j <= m; j++)
			lst[j] = 0;
		for (int j = i; j <= n; j++) {
			int now = a[j];
			if (lst[now] == 0) {
				cards[++tot] = now;
				lst[now] = tot;
			} else {
				while (tot >= lst[now])
					tot--;
				cards[++tot] = now, lst[now] = tot;
			}
		}
		for (int j = 1; j <= tot; j++)
			cnt[cards[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}