#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int C,T;
int n;
ll d,a[N];
int dis[N];
ll cnt[N];
void bfs(int st)
{
	fill(dis+1,dis+n+1,-1);
	fill(cnt+1,cnt+n+1,0);
	queue<int>q;
	q.push(st);
	dis[st]=0;
	cnt[st]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=1;v<=n;v++)
			if(abs(a[u]-a[v])<=d)
			{
				if(dis[v]==-1)
				{
					dis[v]=dis[u]+1;
					cnt[v]=cnt[u];
					q.push(v);
				}
				else if(dis[v]!=-1&&dis[u]+1==dis[v])cnt[v]+=cnt[u];
			}
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2)
				ans++;
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
Ô¤¼Æ40 
*/ 
