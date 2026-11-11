#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,t,n,m,i,j,k,l,a[2000001],f[2000001],g[2000001],s,sum;
int getint()
{
	int sum=0,f=1;
	char a=getchar();
	while(a<48&&a!='-'||a>57)
	  a=getchar();
	if(a=='-')
	{
		f=-1;
		a=getchar();
	}
	while(a>=48&&a<=57)
	{
		sum=sum*10+a-48;
		a=getchar();
	}
	return sum*f;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	id=getint();
	t=getint();
	while(t--)
	{
		int cl=clock();
		sum=0;
		n=getint();
		m=getint();
		for(i=1;i<=n;i++)
		   a[i]=getint();
		if(id==11||id==12)
		{
			for(i=1;i<=n&&a[i]-a[1]<=m;i++);
			i-=2;
			if(i<=1)
			  printf("0\n");
			else
			  printf("%lld\n",max(0ll,n-i*2+1));
			continue;
		}
		for(i=1;i<=n;i++)
		{
			memset(f,0,(n+1)*8);
			memset(g,0,(n+1)*8);
			f[i]=g[i]=s=1;
			for(j=i;j<n;j=k)
			{
				for(k=j+1;k<=n&&a[k]-a[j]<=m;k++)
				   g[k]=g[j]+1;
				k--;
				if(j==k)
				  break;
			}
			for(j=i+1,k=l=i;j<=n&&g[j];j++)
			{
				if(g[j]>g[k]+1)
				{
					s=0;
					l=k+1;
					for(k++;g[j]==g[k]+1;k++)
					   s+=f[k];
					k--;
				}
				for(;l<=k&&a[j]-a[l]>m;l++)
				   s-=f[l];
				f[j]=s;
				if(s==2)
				  sum++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
