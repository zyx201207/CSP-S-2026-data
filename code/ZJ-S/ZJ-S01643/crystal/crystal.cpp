#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define gc() getchar()
#define pc(x) putchar(x)

int read()
{
	int x=0,f=1;
	char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}

void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');return ;}
	write(x/10);pc(x%10+'0');
	return ;
}

void print(int x)
{
	write(x);pc('\n');
	return ;
}

int n,m;
int ans;
int a[500010];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int r=n,l=n;
	int cnt=0;
	while(r>0)
	{
		while(l>1&&cnt+a[r]-a[l-1]<=m)
		{
			cnt+=a[r]-a[l-1];
			l--;
		}
		ans=max(ans,r-l+1);
		cnt-=(r-l)*(a[r]-a[r-1]);
		r--;
	}
	print(ans);
	return 0;
}
