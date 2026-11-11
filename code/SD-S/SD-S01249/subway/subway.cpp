#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+10;
const int N=5e2+10;
int c,n,m,q,d;
ll w[M];
int cnt[M];
int k[N];
struct node{
	int p;
	ll ct;
}t[M][25];
ll f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) f[i][j]=(ll)1e16;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&x,&y);
			t[x][++cnt[x]].ct=(ll)y;
			t[x][cnt[x]].p=i;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=1;k<=cnt[i];k++)
			{
				if(j==k) continue;
				f[t[i][j].p][t[i][k].p]=min(f[t[i][j].p][t[i][k].p],t[i][j].ct+t[i][k].ct);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll ans=(ll)1e16;
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=1;j<=cnt[x];j++)
		{
			for(int k=1;k<=cnt[y];k++)
			{
				ans=min(ans,w[x]+w[y]+t[x][j].ct+t[y][k].ct+f[t[x][j].p][t[y][k].p]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//Oct31==Dec25?
