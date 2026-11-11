#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6+10;


ll n,m,zz[MAXN],a[MAXN],ans[MAXN];
map<ll,ll> mp;


int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll tt = 0;
		for(int j=i;j<=n;j++)
		{
			tt++;
			if(!mp[a[j]])
			{
				mp[a[j]] = tt;
				zz[tt] = a[j];
			}
			else
			{
				for(int k=tt;k>mp[a[j]];k--)
				{
					zz[tt] = 0;
					tt--;
				}
			}
		}
		for(int j=1;j<=tt;j++)
		{
			ans[zz[j]]++;
		}
		memset(zz,0,sizeof(zz));
		for(int i=1;i<=m;i++)
		{
			mp[i] = 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
