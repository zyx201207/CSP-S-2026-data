#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=505;
struct node{int l,t;};
int w[N];
vector<node> a[N];
int mp[M][M];
int dp[M][M];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; cin >>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++) cin >>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin >>k;
		for(int j=1;j<=k;j++)
		{
			int pl,t; cin >>pl >>t;
			a[pl].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=2e18;
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++) for(int k=j+1;k<a[i].size();k++)
		{
			int u=a[i][j].l,v=a[i][k].l;
			mp[u][v]=min(mp[u][v],a[i][j].t+a[i][k].t);
			mp[v][u]=mp[u][v];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	}
	while(q--)
	{
		int x,y; cin >>x >>y;
		int ans=2e18;
		for(node i:a[x]) for(node j:a[y])
		{
			ans=min(ans,w[x]+w[y]+mp[i.l][j.l]+i.t+j.t);
		}
		cout <<ans <<'\n';
	}
	return 0;
}