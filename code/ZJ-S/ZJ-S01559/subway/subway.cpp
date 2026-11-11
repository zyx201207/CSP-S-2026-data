#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500010];
int k[510],a[510][1010];
ll t[510][1010];
int tid,n,m,N,q;
int l,r;
bool v[510][1010];
ll ans=1e18;
inline void dfs(int x,int y,ll s,int stp)
{
	if(stp>n||y>k[x]) return;
	if(a[x][y]==r)
	{
		ans=min(ans,s);
		return;
	}
	v[x][y]=1;
	dfs(x,y+1,s,stp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k[i];j++)
			if(a[i][j]!=a[x][y]) dfs(i,j,s+t[i][j]+t[x][y],stp+1);
	v[x][y]=0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tid>>n>>m>>N>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%d %lld",&a[i][j],&t[i][j]);
	}
	while(q--)
	{
		cin>>l>>r;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==l)
				{
					dfs(i,j,0,0);
				}
			}
		}
		cout<<(ll)(ans+w[l]+w[r])<<endl;
	}
	return 0;
}
