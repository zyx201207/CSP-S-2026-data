#include<bits/stdc++.h>
using namespace std;
int w[100010];
int a[510][510];
struct node{
	int to,l;
};
int mp[500010][510];
struct node3{
	int idx,l;
	long long t;
};
vector<node>edge[500010];
bool vis[500010];
int c,n,m,d,Q;
static inline int bfs(int st,int en)
{
	for(int i=1;i<=m;i++)
		vis[i] = 0;
	queue<node3>q;
	q.push({st,0,w[st]});
	long long minn = 1e18;
	while(!q.empty())
	{
		node3 t = q.front();
		q.pop();
		if(t.idx==en)
		{
			return w[en]+t.t+a[t.l][mp[t.idx][t.l]];
		}
		for(auto i : edge[t.idx])
		{
			if(t.idx==st)
			{
				if(!vis[i.to])
				{
					q.push({i.to,i.l,t.t+a[i.l][mp[t.idx][i.l]]});
					vis[i.to] = 1;
				}
			}
			else if(t.l==i.l)
			{
				if(!vis[i.to])
				{
					q.push({i.to,i.l,t.t});
					vis[i.to] = 1;
				}
			}
			else
			{
				if(!vis[i.to])
				{
					q.push({i.to,i.l,t.t+a[t.l][mp[t.idx][t.l]]+a[i.l][mp[t.idx][i.l]]});
					vis[i.to] = 1;
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int>v;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x>>a[i][j];
			mp[x][i] = j;
			v.push_back(x);
		}
		for(int j=0;j<v.size()-1;j++)
		{
			edge[v[j]].push_back({v[j+1],i});
			edge[v[j+1]].push_back({v[j],i});
		}
	}
	while(Q--)
	{
		int r,c;
		cin>>r>>c;
		cout<<bfs(r,c)<<'\n';
	}
	return 0;
}
