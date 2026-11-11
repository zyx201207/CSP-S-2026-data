#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

inline long long read()
{
	char c=getchar();
	while(!isdigit(c)&&c!='-')
	{
		c=getchar();
	}
	bool flag=false;
	if(c=='-')
	{
		flag=true;
		c=getchar();
	}
	long long val=0;
	while(isdigit(c))
	{
		val=(val<<3)+(val<<1)+1ll*(c^48);
		c=getchar();
	}
	if(flag)
	{
		val=-val;
	}
	return val;
}
int c,T;
long long n,d;
long long a[N];
long long ne[N];
long long ans=0;

void bfs(int deep,int u,int t,int maxn)
{
	if(deep==maxn&&u==t)
	{
		ans++;
	}
	if(deep>maxn)
	{
		return ;
	}
	for(int i=u+1;i<=ne[u];i++)
	{
		bfs(deep+1,i,t,maxn);
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					ne[i]=j;
				}
				else
				{
					break;
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long sum=0;
				long long cnt=1;
				int u=i;
				while(ne[u]<j)
				{
					u=ne[u];
					cnt++;
				}
				bfs(0,i,j,cnt);
				ans--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}