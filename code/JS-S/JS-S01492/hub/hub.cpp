#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
int C,T,n,k;
vector<int> a[2000005];
int h[2000005],maxh=0;
void dfs(int x,int fa)
{
	// cout<<x<<endl;
	h[x]=h[fa]+1;maxh=max(maxh,h[x]);
	for(int i = 0;i < a[x].size();i++)
	{
		if(a[x][i]!=fa)
		{
			dfs(a[x][i],x);
		}
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
	while(T--)
	{
		n=read();k=read();
		for(int i = 1;i <= n;i++)a[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u=read(),v=read();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0);
		write(n/maxh);
		putchar('\n');
	}
	return 0;
}