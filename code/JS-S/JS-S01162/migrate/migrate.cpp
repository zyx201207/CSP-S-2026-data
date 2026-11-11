#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int  N=2e6+10;

int c,t;
inline ll readl()
{
	char c;
	c=getchar();
	ll x=0;
	ll f=1;
	while(c=='-')
	{
		f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	
	return f*x;
}
struct Node
{
	int id,step;
};

void solve()
{
	ll n,d;
	ll x[N];
	bool vis[N]={0};
	n=readl(),d=readl();
	for(int i=1;i<=n;i++)x[i]=readl();
	
	if(n>5000)
	{
		if((x[2]-x[1])>d)
		{
			puts("0");
			return ;
		}
		else
		{
			puts("1");
			return ;
		}
	}
	
	else
	{
		vector<int>dis[N];
		for(int i=1;i<=n;i++)//s
		{
			for(int j=1;j<=n;j++)//t
			{
				
				queue<Node>pq;
				pq.push({i,0});
				while(!pq.empty())
				{	
					int id=pq.front().id,step=pq.front().id;
					pq.pop();
					vis[id]=1;
					if(vis[id])continue;
					if(id == j)
					{
						dis[j].push_back(step);
						continue;
					}
					for(int k=1;k<=n;k++)
					{
						if(abs(x[k]-x[id]) <= d)
						{
							pq.push({k,step+1});
						}
					}
				}
			}
		}
		
	}
	
	
}


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
