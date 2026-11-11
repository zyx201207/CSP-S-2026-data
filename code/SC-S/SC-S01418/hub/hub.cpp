#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, t, n, k, maxn;
vector<ll> connect[1000005];

ll fx(ll pos, ll no)
{
	ll stam = 0;
	if (connect[pos].size() == 1ul && connect[pos].front() == no)
		return 1;
	for (ll& val : connect[pos])
	{
		if (val == no)
			continue;
		stam = max(stam, fx(val, pos) + 1);
	}
	return stam;
}

// RP++
int main()
{
	freopen("hub.in", "r", stdin);
//	freopen("..\\csps\\down\\hub\\hub4.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("..\\csps\\down\\hub\\hub.out", "w", stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	
	scanf("%lld%lld", &c, &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &k);
		for (int i = 0; i < n - 1; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			connect[x].push_back(y);
			connect[y].push_back(x);
		}
		
		for (int i = 1; i <= n; i++)
			maxn = max(maxn, fx(i, i));
		
		for (int i = 1; i <= n; i++)
			connect[i].clear();
		
//		cout << maxn << '|';
		printf("%lld%s", (maxn - k + 2) / 3, t ? "\n" : "");
	}
	
	return 0;
}