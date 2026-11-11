#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],d[500010],maxx;

void in(int &x)
{
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}

void out(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

void dfs(int u,int num,int all,int last)
{
	if(num<0) 
	{
		maxx=max(maxx,all);
		return;
	}
	if(u>n)
	{
		maxx=max(maxx,all);
		return;
	}
	dfs(u+1,num-all*last-d[u+1],all+1,last+d[u+1]);
	dfs(u+1,num,all,last);
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	in(n),in(m);
	for(int i=1;i<=n;i++) in(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	dfs(1,m,0,0);
	cout<<maxx;
	return 0;
}

