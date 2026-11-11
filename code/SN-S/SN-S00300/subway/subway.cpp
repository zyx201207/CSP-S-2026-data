#include<bits/stdc++.h>

using namespace std;
long long c,n,m,d,q;
long long ww[505],k[505],a[505],t[505][505],l[505],r[505];
long long dis[505],ans[505];
bool vis[505];
vector< pair<int,int> >e[505];

void dfs(int u)
{
	queue<int> g;
	g.pop();
	g.push(u);
	vis[u]=true;
	if(!g.empty())
	{
		for(auto &p:e[u])
		{
			int v=p.first;
			int w=p.second;
			if(!vis[v])
			{
				if(dis[u]+w<dis[v])
				{
					dis[v]=dis[u]+w;
				}
			}
			dfs(v);
		}
    }
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[i][a[j]];
		}
		for(int j=1;j<k[i];j++)
		{
			e[a[j]].emplace_back(a[j+1],t[i][a[j]]+t[i][a[j+1]]);
			e[a[j+1]].emplace_back(a[j],t[i][a[j]]+t[i][a[j+1]]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++)
	{
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dis[l[i]]=0;
		dfs(l[i]);
		ans[i]=dis[r[i]];
		ans[i]=ans[i]+ww[l[i]]+ww[r[i]];
		cout<<ans[i]<<"\n";
	}
	return 0;
}
