#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3,INF=1e9;
int c,t;
int n;
long long d,x[maxn+5];
int f[maxn+5][maxn+5];
long long ans=0,g[maxn+5][maxn+5];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		sort(x+1,x+n+1);
		ans=0;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=INF;
		int l=1,r=2;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d) f[i][j]=1,g[i][j]=1;
				else break;
			}
		}
		for(int len=1;len<=n;len++)
		{
			for(int i=1;i<=n-len;i++)
			{
				int j=i+len;
				for(int k=i;k<=j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				for(int k=i;k<=j;k++)
				{
					if(f[i][k]+f[k][j]==f[i][j])
					{
						g[i][j]++;
					}
				}
				if(g[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
