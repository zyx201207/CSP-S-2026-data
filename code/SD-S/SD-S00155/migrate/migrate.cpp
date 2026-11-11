#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=5010;
int c,t,n,m,a[N];
int abss(int x)
{
	if(x<0) return -x;
	return x;
}
vector<int> vc[N];
deque<int> q;
int dis[M],cnt[M];
bool vis[N];
void bfs(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	q.push_back(st);
	dis[st]=0;
	cnt[st]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:vc[u])
		{
			if(dis[v]==dis[u]+1)
			{
				//cout<<u<<"->"<<v<<"  0\n";
				cnt[v]+=cnt[u];
			}
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				if(!vis[v]) q.push_back(v);
				//cout<<cnt[u]<<" "<<u<<"->"<<v<<"   1\n";
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abss(a[i]-a[j])<=m)
			{
				vc[i].push_back(j);
				vc[j].push_back(i);
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i;j<=n;j++)
		{
			if(cnt[j]==2) ans++;
			//cout<<dis[j]<<" ";
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) vc[i].clear();
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
