#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
vector<pair<int,int> >ans[N];
int c,n,m,d,q;
int w[N],k[N],a[510][1010],t[510][1010],vis[N],f[N];
struct node{
	int u,v,w;
};
vector<node>G[N];
vector<int>g[N];
void dfs(int rt,int fa,int ans)
{

	vis[rt]=ans;
	for(int i=0;i<G[rt].size();i++)
	{
		int t1=G[rt][i].u,t2=G[rt][i].v,t3=G[rt][i].w;
		if(t3==fa)
			dfs(t1,t3,ans-t[t3][rt]+t2);
		else
			dfs(t1,t3,ans+t2);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			for(int kk=1;kk<j;kk++)
				G[a[i][kk]].push_back({a[i][j],t[i][j],i});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<G[x].size();j++)
			dfs(x,G[x][j].w,G[x][j].v);
		cout<<vis[y]+w[x]+w[y]<<"\n";
	}
	
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
