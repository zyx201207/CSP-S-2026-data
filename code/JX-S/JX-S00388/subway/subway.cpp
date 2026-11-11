#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,tt[505][500005],w[500005],uu,v,cnt[500005];
bool s[500005];
struct node
{
	int to,j;
};
vector<node> e[500005];
long long mint;
void dfs(int u,int b,long long t)
{
	if(u==v) {mint=min(mint,t+tt[b][v]); return ;}
	if(e[u].empty()) return ;
	if(cnt[u]<2 && u!=uu) dfs(e[u][0].to,b,t);
	for(node i:e[u])
	{
		if(b==i.j) dfs(i.to,i.j,t);
		else dfs(i.to,i.j,t+tt[b][u]+tt[i.j][u]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		int pre;
		for(int j=1;j<=k;j++)
		{
			int u;
			cin>>u;
			cnt[u]++;
			cin>>tt[i][u];
			if(j!=1)
			{
				e[pre].push_back({u,i});
			}
			pre=u;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>uu>>v;
		mint=1e18;
		dfs(uu,0,0);
		swap(uu,v);
		dfs(uu,0,0);
		cout<<mint+w[uu]+w[v]<<"\n";
	}
	return 0;
}
