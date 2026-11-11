#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5050;
int c,n,m,d,q,w[MAXN],k[MAXN][MAXN],a[MAXN][100],b[MAXN][100],l[MAXN],r[MAXN];
int dfs(int ans,int zd,int lx,int czd)
{
	if(zd==czd) return ans;
	dfs(ans,b[zd][lx],lx,czd);
	for(int i=1;i<=n;i++)
	{
		if(a[zd][i]!=0) dfs(ans+a[zd][lx]+a[zd][i],zd,i,czd);
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i][0];
		int szd;
		for(int j=1;j<=k[i][0];j++)
		{
			int x,y;
			cin>>x>>y;
			a[x][i]=y;
			if(j!=1)
			{
				b[szd][i]=x;
			} 
			szd=x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
		int maxn=1e9;
		for(int j=1;j<=n;j++)
		{
			if(a[l[i]][j]!=0) maxn=max(maxn,dfs(0,l[i],j,r[i]));
		}
		cout<<maxn+w[l[i]]+w[r[i]]<<endl;
	}
	return 0;
} 
