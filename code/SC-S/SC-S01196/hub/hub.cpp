#include<bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x)
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
}
void write(int x)
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
}
vector<int>nex[1000006];
int dep[1000006];
void dfs(int now,int fa)
{
	for(auto e:nex[now])
	{
		if(e==fa)
		{
			continue;
		}
		else
		{
			dep[e]=dep[now]+1;
			dfs(e,now);
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	read(c),read(t);
	while(t--)
	{
		int n,k;
		read(n),read(k);
		for(int i=1;i<=n;i++)
		{
			nex[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			nex[u].push_back(v);
			nex[v].push_back(u);
		}
		dep[1]=1;
		dfs(1,0);
		if(n<=k)
		{
			write(0);
			putchar('\n');
		}
		else
		{
			sort(dep+1,dep+n+1,greater<int>());
			int ans=0;
			for(int i=n;i>k;i--)
			{
				ans+=dep[k]-dep[i];
			}
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}