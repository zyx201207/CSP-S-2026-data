#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m, a[N], cnt[N], pre[N], nxt[N];
ll d[N], s[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(pre[a[i]])
			nxt[pre[a[i]]] = i;
		pre[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		s[i] += s[i - 1];
		int t = i - s[i];
		if(!nxt[i]) continue;
		s[i] += t;
		s[nxt[i]] -= t;
	}
	for(int i = 1; i <= n; i ++)
		cnt[a[i]] += i - s[i];
	for(int i = 1; i <= m; i ++)
		cout << cnt[i] << " \n"[i == m];
	return 0;
}
