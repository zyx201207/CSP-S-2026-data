#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
ll f[505][505];
ll n,m,d,q;
int c;
ll w[505],t[505],a[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) f[i][j]=0;
			else f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++){
			for(int z=j+1;z<=k;z++)
			{
				int u=a[j],v=a[z];
				f[u][v]=f[v][u]=t[j]+t[z];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i==j||j==k||i==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=f[u][v]+w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
