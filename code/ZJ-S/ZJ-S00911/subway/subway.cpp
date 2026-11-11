#include<bits/stdc++.h>
using namespace std;
const int slen=1e5+10;
int w[25];
struct info
{
	int to,w,bian,leixing;
};
vector<info> e[slen];
int out[slen];
int vis[slen],bis[slen];
int dfs(int node,int x)
{
	int last=0;
	for(int i=0;i<e[node].size();i++)
	{
		int to=e[node][i].to;
		out[to]--;
		bis[node]=e[node][i].leixing;
		if(bis[to]==bis[node])
			vis[to]=min(vis[to],vis[node]+e[node][i].w);
		if(e[node][i].leixing!=bis[node]&&bis[node]!=0)
		{
			vis[to]=min(vis[to],vis[node]+e[node][i].w*2+last);
		}
		last=e[node][i].w;
		dfs(to,x);
	}
	return vis[x];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;int last=0;
		for(int j=1;j<=k;j++)
		{
			int u,t;cin>>u>>t;
			if(j!=1)
			{
				out[last]++;
				e[u].push_back({last,i,k,j});
			}
			else	e[u].push_back({0,i,k,j});
			last=u;
		}
	}
	while(q--)
	{
		memset(vis,0x7f,sizeof(vis));
		int x,y;cin>>x>>y;
		int ans=0;ans+=w[y];
		vis[y]=0;
		ans+=dfs(y,x);
		ans+=w[x];
		cout<<ans<<endl;
	}
	return 0;
}