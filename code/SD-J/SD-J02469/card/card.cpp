#include<bits/stdC++.h>
#define int long long
using namespace std;
const int maxN=5e5+5,maxM=3e5+5;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int n,nnn,nn,mm,m;
int a[maxN],ans[maxM],ls[maxN];
int s(int e,int x)
{
	while(e--)
	{
		if(ls[e+1]==x) return e+1;
	}
	return -1;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	nnn=nn=n,mm=m;
	while(nnn--)
	{
		a[n-nnn]=read();
	}
	while(nn--)
	{
		int t=0;
		for(int j=n-nn;j<=n;j++)
		{
			int x=s(t+1,a[j]);
			if(x!=-1) t=x-1;
			ls[++t]=a[j];
		}
		for(int j=1;j<=t;j++)
		{
			ans[ls[j]]++;
		}
	}
	while(m--)
	{
		printf("%d ",ans[mm-m]);
	}
	return 0;
}


