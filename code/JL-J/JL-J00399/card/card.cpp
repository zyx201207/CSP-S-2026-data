#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 500005;

ll n, m;
ll a[maxn];
ll ans[maxn];
ll tab[maxn];

ll have(ll x, ll o);

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(tab, 0, sizeof(tab));
		for(int j = i; j <= n; j++)
		{
			if(have(a[j], i))
			{
				for(int k = have(a[j], i); k <= n; k++)
					tab[k] = 0;
			}
			tab[j] = a[j];
		}
		for(int j = i; j <= n; j++) ans[tab[j]]++; 
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i];
		if(m - i) cout << ' ';
	}
	return 0;
}

ll have(ll x, ll o)
{
	for(ll i = o; i <= n; i++)
	{
		if(tab[i] == x) return i;
	}
	return 0;
}






