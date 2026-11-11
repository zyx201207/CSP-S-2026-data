#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,m,dis[N];
vector<int> vc[N];
deque<int> q;
bool vis[N];
void dfs(int u)
{
	vis[u]=0;
	for(int v:vc[u])
	{
		if(vis[v]) dfs(v);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	int ans=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0;
		q.clear();
		for(int j=1;j<=n;j++)
		{
			dis[j]=1e9;
			vis[j]=0;
			if(i>>(j-1)&1)
			{
				cnt++;
				//cout<<j<<" ";
				q.push_back(j);
				dis[j]=0;
				vis[j]=1;
			}
		}
		//cout<<"\n";
		if(cnt!=m) continue;
		int bl=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				//cout<<j<<" ";
				bl++;
				dfs(j);
			}
		}
		//cout<<bl<<"_______\n";
		if(bl>2) continue;
		int mx=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop_front();
			//cout<<u<<" ";
			mx=max(mx,dis[u]);
			for(int v:vc[u])
			{
				if(dis[v]>dis[u]+1)
				{
					dis[v]=dis[u]+1;
					q.push_back(v);
				}
			}
		}
		//cout<<mx<<"\n";
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) vc[i].clear();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
