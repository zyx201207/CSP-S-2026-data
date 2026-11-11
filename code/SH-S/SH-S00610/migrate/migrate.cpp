#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
vector<int> bfs01(int x,vector<vector<int> > mp)
{
	queue<int> q;
	q.push(x);
	vector<int> dis(mp.size(),INF);
	vector<bool> vis(mp.size(),0);
	vector<int> rst(mp.size(),0);
	dis[x]=0;
	rst[x]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<mp[u].size();i++)
		{
			if(dis[mp[u][i]]>dis[u]+1)
			{
				dis[mp[u][i]]=dis[u]+1;
				rst[mp[u][i]]=rst[u];
				q.push(mp[u][i]);
			}
			else if(dis[mp[u][i]]==dis[u]+1)
			{
				rst[mp[u][i]]+=rst[u];
			}
		}
	}
	
	return rst;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		vector<int> nums(n);
		for(int i=0;i<n;i++)
		{
			cin>>nums[i];
		}
		vector<vector<int> > mp(n);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(nums[j]-nums[i]>d) break;
				mp[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			vector<int> rst=bfs01(i,mp);
			for(int j=i;j<n;j++)
			{
				if(rst[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
