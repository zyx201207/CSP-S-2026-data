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
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int bh;
ll T,n,d,ans,a[2000010],c[7005][7005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=0;i<=3000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||i==j)c[i][j]=1;
			else c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	bh=read();T=read();
	while(T--)
	{
		n=read();d=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<n;i++)
		{
			int l=i+1,r=n;
			while(l<r)
			{
				int mid=l+r>>1;
				if(a[mid]<=a[i]+d)l=mid+1;
				else r=mid;
			}
			if(a[l]!=a[i]+d+1)continue;
			for(int j=l;j<=n;j++)
				if(c[j-i-1][(a[j]-a[i]-1)/d]==2)ans++;
		}
		write(ans);
		puts("");
	}
	return 0;
}
