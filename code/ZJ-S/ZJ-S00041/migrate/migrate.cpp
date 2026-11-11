#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
vector<int> G[N];
int f[N],dis[N],x[N];
int n;
void solve(int s)
{
	for(int i=1;i<=n;i++) dis[i]=N,f[i]=0;
	queue<int> q;
	q.push(s);
	dis[s]=0;
	f[s]=1;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i:G[cur])
		{
			if(dis[i]!=N)
			{
				if(dis[i]==dis[cur]+1)
				{
					f[i]+=f[cur];
					if(f[i]>3) f[i]=3;
				}
			}
			else
			{
				dis[i]=dis[cur]+1;
				f[i]=f[cur];
				q.push(i);
			}
		}
		
	}
}
void solve()
{
	int d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		G[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		int ls=lower_bound(x+1,x+n+1,x[i]-d)-x;
		int rs=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		for(int j=ls;j<=ls+2&&j<i;j++) G[i].push_back(j);
		for(int j=rs;j>=rs-2&&j>i;j--) G[i].push_back(j);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		solve(i);
		for(int j=1;j<=n;j++)
		{
			if(f[j]==2) ans++;
		}
	}
	cout<<ans/2<<'\n';
}
signed main()//40
{
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

