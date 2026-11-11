#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	char c;
	c=getchar();
	int u=1;
	while(!isdigit(c))
	{
		if(c=='-')
		{
			u=-1;
		}
		c=getchar();
	}
	x=0;
	while(isdigit(c))
	{
		x=x*10;
		x+=c-'0';
		c=getchar();
	}
	x=x*u;
	return;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10)
	{
		write(x/10);
	}
	char c=x%10+'0';
	putchar(c);
	return;
}
const int N=5e5+5;
int a[N],d[N],pre[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	sort(a+1,a+n+1);
	pre[0]=0;
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
		pre[i]=pre[i-1]+d[i];
	}
	int sum=0;
	int la=1;
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		sum+=(i-la)*d[i-1];
		while(sum>m)
		{
			sum-=(pre[i-1]-pre[la-1]);
			la++;
		}
		ans=max(ans,i-la+1);
	}
	write(ans);
	return 0;
}