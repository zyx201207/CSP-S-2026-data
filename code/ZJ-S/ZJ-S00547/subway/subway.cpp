#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=510,maxm=1010;
const long long INF=0x3fffffffffffffff;
int c,n,m,d,q;
int k[maxn],w[maxm];
int x,y;
ll a[maxm],t[maxm],f[maxm][maxm];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=maxm;i++)
		for(int j=1;j<=maxm;j++)
			f[i][j]=INF;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld %lld",&a[j],&t[j]);
		for(int j=1;j<=k[i];j++)
		{
			for(int l=j+1;l<=k[i];l++)
			{
				f[a[j]][a[l]]=f[a[l]][a[j]]=(ll)t[j]+(ll)t[l];
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int l=1;l<=m;l++)
				if(i!=j&&i!=l)
				{
					f[i][j]=min(f[i][j],f[i][l]+f[j][l]);
				}
	while(q--)
	{
		scanf("%d %d",&x,&y);
		printf("%lld\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}
//
