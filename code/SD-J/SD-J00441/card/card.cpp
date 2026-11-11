#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, m;
int a[MAXN], mp[MAXN], st[MAXN], tl, ans[MAXN];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int ii = 1; ii <= n; ii++) {
		for (int i = 1; i <= m; i++) mp[i] = 0;
		tl = 0;
		for (int i = ii; i <= n; i++) {
			if (mp[a[i]]) {
				while (tl >= mp[a[i]] && mp[a[i]]) mp[st[tl--]] = 0;
			}
			st[++tl] = a[i];
			mp[a[i]] = tl;
		}
		for (int i = 1; i <= tl; i++) {
			ans[st[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << '\n';
}
