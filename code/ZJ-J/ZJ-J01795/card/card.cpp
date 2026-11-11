#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
void write(ll x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll n,m,t,a[500010],b[500010],f[300010];
int fin(ll x)
{
	int l=1,r=t;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(b[mid]==x)return mid;
		if(b[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=i;j<=n;j++)
		{
			int id=fin(a[j]);
			b[++t]=a[j];
			if(id!=-1)t=id;
		}
		for(int j=1;j<=t;j++)f[b[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		write(f[i]);
		putchar(' ');
	} 
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
