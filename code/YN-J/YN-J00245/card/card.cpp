// c - j - c 2026 10 31 csp T4
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n, m, a[N], p[N];
long long ans[N], tot;
map<long long, long long>mp;

int main(void) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mp[a[i]] = i;
	if (n < 5000) {
		bool f = 0;
		for (int u = 1; u <= n; u++) {
			tot = 0;
			for (int i = u; i <= n; i++) {
				f = 0;
				for (int j = 1; j <= tot; j++) {
					if (p[j] == a[i]) {
						tot = j;
						f = 1;
						break;
					}
				}
				if (!f)
					p[++tot] = a[i];
			}
			for (int i = 1; i <= tot; i++)
				ans[p[i]]++;
		}
		for (int i = 1; i <= m; i++)
			cout << ans[i] << " ";
	} else {
		for (int i = 1; i <= m; i++)
			cout << mp[i] << " ";
	}
	return 0;
}