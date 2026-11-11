#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll inf=1e18;
ll f[520][520];
ll n,m,d,q,c;
ll w[500010];
struct Node
{
	ll a,b;
 };
vector<Node> e[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<=500;i++)
		for(int j=0;j<=500;j++)
			f[i][j]=inf;
	for(int i=0;i<=500;i++)
		f[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int p=1;p<=m;p++)
		for(int i=0;i<(ll)e[p].size();i++)
		{
			ll u=e[p][i].a,uw=e[p][i].b;
			for(int j=i+1;j<(ll)e[p].size();j++)
			{
				ll v=e[p][j].a,vw=e[p][j].b;
				f[u][v]=f[v][u]=min(f[u][v],uw+vw);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<f[i][j]<<" \n"[j==n];
	while(q--)
	{
		ll u,v,mn=inf;
		cin>>u>>v;
		for(int i=0;i<e[u].size();i++)
			for(int j=0;j<e[v].size();j++)
				mn=min(mn,e[u][i].b+e[v][j].b+f[e[u][i].a][e[v][j].a]);
		cout<<mn+w[u]+w[v]<<'\n';
	}
	return 0;
}
