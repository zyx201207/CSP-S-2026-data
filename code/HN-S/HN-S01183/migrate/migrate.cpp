#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d;
ll x[2000006];  
ll de[2000006];
ll num[2000006];
void dfs(ll p,ll dep)
{
	for(int i = p + 1;;i ++)
	{
		if(x[i] - x[p] > d)
			break;
		if(de[i] > dep + 1)
		{
			de[i] = dep + 1;
			num[i] = 1;
			dfs(i,dep + 1);
		}
		else if(de[i] == dep + 1)
		{
			num[i] ++;
			dfs(i,dep + 1);
		}
		else
			return ;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T --)
	{
		ll ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)
			cin >> x[i];
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i + 1;j <= n;j ++)
			{
				de[j] = 1e18;
				num[j] = 0;
			}
			dfs(i,0);
			for(int j = i + 1;j <= n;j ++)
			{
				if(num[j] == 2) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
 } 
