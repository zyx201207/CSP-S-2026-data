#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
struct node
{
	int v,w;
};
int c,n,m,d,Q;
int w[500005];
vector<node> g[100005];
priority_queue<PII,vector<PII>,greater<PII> > q;
int dis[100005],f[100005];
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(f,0,sizeof(f));
	dis[s]=0;
	f[s]=1;
	q.push({0,s});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		for(auto v:g[u.second])
		{
			if(f[v.v]) continue;
			if(dis[v.v]>dis[u.second]+v.w)
			{
				dis[v.v]=dis[u.second]+v.w;
				q.push({dis[v.v],v.v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		m++;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			g[m].push_back({v,w});
			g[v].push_back({m,w});
		}
	}
	while(Q--)
	{
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<dis[t]+w[s]+w[t]<<endl;
	}
	return 0;
}
