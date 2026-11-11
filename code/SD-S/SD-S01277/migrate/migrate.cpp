#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000010],vis[2000010],dis[200010],ans=0;
struct node
{
	long long id,step;
};
void solve()
{
	for(long long i=2;i<=n;i++)
	{
		for(long long j=1;j<=i;j++)
		{
			vis[j]=1e18;
			dis[j]=0;
		}
		queue<node> q;
		node h;
		h.id=i,h.step=0;
		q.push(h);
		vis[i]=0;
		while(!q.empty())
		{
			node g=q.front();
			q.pop();
			long long id=g.id,step=g.step;
			if(step>vis[id])
			{
				continue;
			}
			else if(step==vis[id])
			{
				dis[id]++;
			}
			else
			{
				vis[id]=step;
				dis[id]=1;
			}
			for(long long j=id-1;j>=1;j--)
			{
				if(x[id]-x[j]>d)
				{
					break;
				}
				node gg;
				gg.id=j,gg.step=step+1;
				if(step>vis[j])
				{
					continue;
				}
				q.push(gg);
			}
		}
		for(long long j=1;j<=i;j++)
		{
			if(dis[j]==2)
			{
				ans++;
			}
		}
	}
}
void solve2()
{
	long long ma=d/(x[2]-x[1]);
	if(ma<2)
	{
		return ;
	}
	else if(ma==n)
	{
		
	}
	else
	{
		ans=n-(ma*2-1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long ccc,T;
	scanf("%lld%lld",&ccc,&T);
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		long long flag=1;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			if(i>2&&x[i]-x[i-1]==x[i-1]-x[i-2])
			{
				
			}
			else if(i>2)
			{
				flag=0;
			}
		}
		if(flag==0)
		{
			solve();
		}
		else
		{
			solve2();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
