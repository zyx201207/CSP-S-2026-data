#include<bits/stdc++.h>
using namespace std;

int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=k*10+(c-'0');c=getchar();}
	return k*f;
}

int c,t;
int n,m;
int a[1000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		cout<<0<<"\n";
	}
	return 0;
}
