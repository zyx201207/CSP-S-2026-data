#include<bits/stdc++.h>
#define int long long
#define db double
#define endl "\n"
using namespace std;
const int N=1000010;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int c,T;
int a[N];
int cf[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--)
	{
		int n,d;
		n=read();d=read();
		int flag=0,id;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			cf[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;i++)
		{
			if(cf[i]>d) flag=1;
		}
		if(flag) puts("0");
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]<=h&&a[n]-a[i]<=h) id=i;
			}
			cout<<id*(n-id+1)/2<<endl;
		}
	}
	return 0;
}
