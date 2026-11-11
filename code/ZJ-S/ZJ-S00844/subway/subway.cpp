#include<bits/stdc++.h>
using namespace std;
const int N=780,M=5e5+5;
int c,n,m,d,q;
int w[N],a[N][M],t[N][M],k[N];
int mapp[N][N];
int read()
{
	int a=0,b=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') b*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
int solve(int sta,int end)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int l=1;l<=k[i];l++)
			{
				if(j==l) continue;
			}
		}
	}
}
signed main()
{
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			a[j]=read(),t[j]=read();
		}
	}
	for(int i=1;i<=q;i++)
	{
		int start=read(),end=read();
		cout<<solve(start,end)<<endl;
	}
	return 0;
}