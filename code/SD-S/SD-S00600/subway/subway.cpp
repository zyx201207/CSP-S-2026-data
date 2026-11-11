#include<bits/stdc++.h>
using namespace std;
long long w[500001],ans,zdl[505][505],t[500001][21];
int c,n,m,d,q,k[505],l,r,tu2[500001],tu[500001][21],ppp;
map<int,map<int,int> > a;
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=500;i++)
	{
		for(int j=0;j<=500;j++)
		{
			zdl[i][j]=1145141919810;
		}
	}
	for(int i=0;i<=500;i++)
	{
		zdl[i][i]=0;
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i][j]);
			ppp=a[i][j];
			scanf("%lld",&t[ppp][i]);
			tu2[ppp]++;
			tu[ppp][tu2[ppp]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			ppp=a[i][j];
			for(int j2=1;j2<=tu2[ppp];j2++)
			{
				zdl[i][tu[ppp][j2]]=min(zdl[i][tu[ppp][j2]],t[ppp][i]+t[a[i][j]][tu[ppp][j2]]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int j2=1;j2<=n;j2++)
			{
				zdl[j][j2]=min(zdl[j][j2],zdl[j][i]+zdl[i][j2]);
			}
		}
	}
	for(int ii=1;ii<=q;ii++)
	{
		scanf("%lld%lld",&l,&r);
		ans=11451419198100;
		for(int i=1;i<=tu2[l];i++)
		{
			for(int j=1;j<=tu2[r];j++)
			{
				ans=min(ans,zdl[tu[l][i]][tu[r][j]]+t[l][tu[l][i]]+t[r][tu[r][j]]);
			}
		}
		printf("%lld\n",ans+w[l]+w[r]);
	}
	return 0;
} 
