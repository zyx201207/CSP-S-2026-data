#include<bits/stdc++.h>
using namespace std;
long long c,t,n,ans,d,lll,ge,cnt,x[4000005],dis[4000005];
vector<long long>es[2000005],mp[2000005];
struct abc
{
	long long u,v;	
	bool operator <(const abc & oth) const
	{
		return v>oth.v;
	}
};
void di(long long x)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<abc>q; 
	q.push(abc{x,0});
	while(q.size())
	{
		int u=q.top().u;
		int v=q.top().v;
		q.pop();
		if(v<dis[u])
		{
			dis[u]=v;
			for(auto nxt:es[u])
			{
				if(dis[u]+1<dis[nxt])
				{
					q.push(abc{nxt,1+dis[u]});
				}			
			}
		}
	}
}
void dfs(int zx,int y,int step)
{
	if(step>lll)
	{
		return;
	}	
	if(zx==y&&step==lll)
	{
		cnt++;
		return;
	}
	if(zx>y)
	{
		return;
	}
	for(int i=1;i<=d;i++)
	{
		if(x[i+zx])
		{
			dfs(i+zx,y,step+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			x[i]+=ge;
			if(x[i]<=0)
			{
				ge=1-x[i];
				x[i]=1;
				for(int j=1;j<i;j++)
				{
					x[i]+=ge;
				}
			}
			
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					es[i].push_back(j);
					es[j].push_back(i); 
				}
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			di(i);
			for(int j=1;j<=n;j++)
			{
				if(j==i||abs(j-i)<=d)
				{
					continue;
				}
				cnt=0;
				lll=dis[j];
				dfs(x[min(i,j)],x[max(i,j)],0);
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

