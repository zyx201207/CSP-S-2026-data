#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;
int n, m, a[N], lasp[N];
int to[N], ind[N], hd, tl, que[N], siz[N];

int main()
{
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i], lasp[a[i]] = i, siz[i] = 1;
	
	for (int i = 1; i < n; ++ i)
		if (i == lasp[a[i]]) to[i] = i + 1, ++ ind[i + 1];
		else to[i] = lasp[a[i]], ++ ind[lasp[a[i]]];
	hd = tl = 0;
	for (int i = 1; i <= n; ++ i)
		if (ind[i] == 0) que[tl ++] = i;
	for (; hd < tl;)
	{
		int u = que[hd ++]; siz[to[u]] += siz[u];
		if (-- ind[to[u]] == 0) que[tl ++] = to[u];
	}
	
	for (int i = 1; i <= m; ++i) cout << siz[lasp[i]] << " \n"[i == m];
	return 0;
}
