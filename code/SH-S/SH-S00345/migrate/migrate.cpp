#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
namespace BFS
{
	int n,d;
	int vis[N][N],dis[N][N][4],x[N];
	vector<int> v[N];
	void bfs(int s,int vis[N],int dis[][4])
	{
		for(int i=1;i<=n;i++) vis[i]=dis[i][0]=dis[i][1]=dis[i][2]=dis[i][3]=0;
		queue<pair<int,int>> q;
		q.push({s,0});
		vis[s]=1;
		while(q.size())
		{
			int x=q.front().first,d=q.front().second;
			q.pop();
			for(auto y:v[x])
			{
				if(vis[y]>3) continue;
				vis[y]++;
				dis[y][vis[y]]=d+1;
				q.push({y,dis[y][vis[y]]});
			}
		}
	}
	void solve()
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			v[i].clear();
			for(int j=i-1;j>=1;j--)
			{
				if(x[i]-x[j]<=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int s=1;s<=n;s++) bfs(s,vis[s],dis[s]);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dis[i][j][1]==dis[i][j][2]&&dis[i][j][2]!=dis[i][j][3])
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	void main()
	{
		int t;
		cin>>t;
		while(t--) solve();
	}
}
namespace rp
{
	int n,d;
	void solve()
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>BFS::x[i];
		cout<<n*(n-1)/2;
	}
	void main()
	{
		int t;
		cin>>t;
		while(t--) solve();
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	int c;
	cin>>c;
	if(c<=10) BFS::main();
	else rp::main();
	return 0;
}

