#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll x[10010],n,d;
ll ans;
bool vis[100010];
ll minn=1e9;
int st,en;
void dfs(int a,ll dis)
{
	if(dis>minn)return;
	if(a==en)
	{
		if(dis==minn)ans++;
		else ans=1;
		minn=min(minn,dis);
		return ;
	}
	for(int i=a+1;i<=en;i++)
	{
		if(x[i]-x[a]<=d)
		{
			dfs(i,dis+1);
		}
		else break;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ll cnt=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int u=1;u<=n;u++)
		{
			for(int v=u;v<=n;v++)
			{
				st=u,en=v;
				ans=0;
				minn=1e9;
				dfs(u,0);
				if(ans==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
