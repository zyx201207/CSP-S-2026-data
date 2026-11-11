#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[510][510],l,r,mid,cnt,far[2000010],nfar[2000010];
long long d,x[2000010],sum,b[510][510];
long long zx[2000010],fx[2000010];
int check(int st,int xl)
{
	int p=st,bo=0,cnt=0;
	while(p<=xl) zx[++cnt]=far[p],p=far[p];
	p=xl;
	while(p>=st)
	{
		fx[--cnt]=nfar[p];
		bo+=abs(zx[cnt]-fx[cnt]);
	}
	if(bo>2) return 0;
	return 1;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int q=1;q<=t;q++)
	{
		scanf("%d%lld",&n,&d);
		for(int j=1;j<=n;j++) scanf("%lld",&x[j]);
		if(c<=6)
		{
			memset(f,0x3f,sizeof(f));
			sum=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					b[i][j]=0;
					if(x[j]-x[i]<=d) f[i][j]=1,b[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++)
			  for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
				{
					if(f[i][j]+f[j][k]<f[i][k])
					{
						f[i][k]=f[i][j]+f[j][k];
						b[i][k]=b[i][j]*b[j][k];
					}
					else if(f[i][j]+f[j][k]==f[i][k]) b[i][k]+=b[i][j]*b[j][k];
				}
			for(int i=1;i<=n;i++)
			  for(int j=i+1;j<=n;j++)
				if(b[i][j]==2) sum++;
			printf("%lld\n",sum);
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				l=0;r=n;
				while(l<=r)
				{
					mid=(l+r)>>1;
					if(x[mid]-x[i]<=d) l=mid+1;
					else r=mid-1;
				}
				far[i]=r;
			}
			for(int i=n;i>=1;i--)
			{
				l=0;r=n;
				while(l<=r)
				{
					mid=(l+r)>>1;
					if(x[i]-x[mid]<=d) l=mid+1;
					else r=mid-1;
				}
				nfar[i]=l;
			}
			sum=0;
			for(int i=1;i<=n;i++)
			{
				l=0,r=n;
				while(l<=r)
				{
					cnt=0;
					mid=(l+r)>>1;
					if(check(i,mid)) l=mid+1;
					else r=mid-1;
				}
				sum+=r;
				sum-=far[i];
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}