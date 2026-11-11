#include<bits/stdc++.h>
#define ll long long
using namespace std;  
ll n,m,c,d,q; 
ll w[500005]; 
vector <ll> p[500005];
vector <ll> t[500005];
ll l[505][505];  
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
		cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		ll k;
		cin >> k;
		for(int j = 1;j <= k;j ++)
		{
			ll x,y;
			cin >> x >> y;
			p[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			l[i][j] = 1e18;
	for(int i = 1;i <= m;i ++)
	{
		for(int j = 0;j < p[i].size();j ++)
			for(int k = 0;k < p[i].size();k ++)
			{
				l[p[i][j]][p[i][k]] = min(l[p[i][j]][p[i][k]],t[i][j] + t[i][k]);
				if(j == k)
					l[p[i][j]][p[i][k]] = 0;
			}
	}
	for(int k = 1;k <= n;k ++)
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
			{
				l[i][j] = min(l[i][j],l[i][k] + l[k][j]);
			}
	for(int i = 1;i <= q;i ++)
	{
		ll x,y,ans = 1e18;
		cin >> x >> y;
		for(int j = 0;j < p[x].size();j ++)
			for(int k = 0;k < p[y].size();k ++)
			{
				ans = min(ans,l[p[x][j]][p[y][k]] + t[x][j] + t[y][k]);
			}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
 } 
