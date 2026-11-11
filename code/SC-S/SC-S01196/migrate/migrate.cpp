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
const int N=2e6+5;
int x[N];
int minn,cnt;
int n,d;
void dfs(int now,int ed,int len)
{
	if(len>minn||(len==minn&&now!=ed))
	{
		return;
	}
	if(now==ed)
	{
		if(minn==len)
		{
			cnt++;
			return;
		}
		if(minn>len)
		{
			minn=len;
			cnt=1;
			return;
		}
	}
	if(len==minn-1)
	{
		if(x[ed]-x[now]<=d)
		{
			dfs(ed,ed,len+1);
			return;
		}
		else
		{
			return;
		}
	}
	for(int i=ed;i>=now+1;i--)
	{
		if(x[i]-x[now]<=d)
		{
			dfs(i,ed,len+1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			read(n),read(d);
			for(int i=1;i<=n;i++)
			{
				read(x[i]);
			}
			int dc=(x[2]-x[1]);
			if(dc*2>d)
			{
				write(0);
				putchar('\n');
			}
			else
			{
				write(max((int)0,n-d/dc-1));
				putchar('\n');
			}
		}
	}
	else while(t--)
	{
		read(n),read(d);
		for(int i=1;i<=n;i++)
		{
			read(x[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=0,minn=1e18;
				if(x[j]-x[i]<=d)
				{
					continue;
				}
				dfs(i,j,0);
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}