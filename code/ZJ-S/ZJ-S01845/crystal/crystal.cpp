#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],c[500005],m,b[500005],maxn;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+(c-'0');
		c=getchar();
	}
	return sum*f;
}
void write(int t)
{
	if(t<0)
	{
		cout<<'-';
		t=-t;
	}
	if(t>10)write(t/10);
	putchar(t%10+'0');
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];	
	}
	for(int t=1;t<=n;t++)
	{
		bool f=0;
		c[t]=0;
		for(int i=t;i<n;i++)
		{
			c[i+1]=b[i]*(i-t+1)+c[i];
		}
		for(int i=t+1;i<=n;i++)
			if(c[i]>m)
			{
				f=1;
					maxn=max(i-t,maxn);
				break;
			}
		if(!f)maxn=max(n-t+1,maxn);
	}
	write(maxn);
	return 0;
}
/*
5 3
1 9 10 11 12
*/
