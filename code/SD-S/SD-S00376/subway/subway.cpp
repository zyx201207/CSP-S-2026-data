#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,ar[500010],t[500010],ans[1500010],vis[1500010];
struct node
{
	ll v,w;
	friend bool operator <(node a,node b)
	{
		return a.w>b.w;
	}
};
vector<node> g[1500010];
void dij(ll fi,ll se)
{
	for(int i=0;i<=2*m+m;i++)
	{
		ans[i]=1e18;
		vis[i]=0;
	}
//	memset(ans,0x3f3f3f3f,sizeof(ans));
//	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({fi,0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		ll u=now.v,val=now.w;
//		cout<<u<<" "<<val<<endl;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			ll to=g[u][i].v,tw=g[u][i].w;
			if(ans[to]>val+tw)
			{
				ans[to]=val+tw;
				q.push({to,ans[to]});
			}
		}
	}
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		ll val;
		cin>>val;
		g[m+i].push_back({i,val});
		g[i].push_back({m+i,val});
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>ar[j]>>t[j];
			g[2*m+i].push_back({ar[j],t[j]});
			g[ar[j]].push_back({2*m+i,t[j]});
		}
	}
//	ll tmp=0;
//	for(int i=1;i<=2*m+m;i++)
//	{
//		tmp+=g[i].size();
//	}
//	cout<<tmp<<endl;
	for(int i=1;i<=q;i++)
	{
		ll be,en;
		cin>>be>>en;
		dij(m+be,m+en);
		cout<<ans[m+en]<<'\n';
	}
	return 0;
}

