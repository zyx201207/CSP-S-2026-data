#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,inf=1e18;
int x[N],ri[N];
int f[N],g[N];//dis,ways
int dep[N],dis[N];
int tag[N];
int ans;	
int n,d;
void sol(int fr)
{
	f[fr]=0;
	g[fr]=1;
	for(int i=fr+1;i<=n;i++)
	{
		f[i]=inf;
		g[i]=0;
	}
	for(int i=fr;i<=n;i++)
	{
		for(int j=i+1;j<=ri[i];j++)
		{
			if(f[j]>f[i]+1)
			{
				f[j]=f[i]+1;
				g[j]=g[i];
			}
			else if(f[j]==f[i]+1)
			{
				g[j]+=g[i];
				if(g[j]>=3)
				{
					g[j]=3;
				}
			}
		}
	}
	for(int i=fr+1;i<=n;i++)
	{
		ans+=(g[i]==2);
	}
}
void add(int l,int r,int v,int v2)
{
	//cout<<l<<" "<<r<<" "<<v<<"\n";
	if(l>r)
	{
		return;
	}
	g[l]+=v;
	tag[l]+=v2;
	tag[r+1]-=v2;
	if(v<10000000ll)
	{
		g[r+1]-=v;
	}
}
void sol2(int fr)
{
	for(int i=1;i<=n;i++)
	{
		g[i]=0;
		dis[i]=0;
		dep[i]=0;
		tag[i]=0;
	}
	g[fr]=1,g[fr+1]=-1,g[fr-1]=0;
	int now=fr,idx=2;
	dep[1]=fr;
	while(now!=ri[now])
	{
		now=ri[now];
		dep[idx]=now;
		idx++;
	}
	dis[fr]=1;
	for(int i=1;i<idx-1;i++)
	{
		for(int j=dep[i]+1;j<=dep[i+1];j++)
		{
			dis[j]=i+1;
		}
	}
//	for(int i=fr;i<=n;i++)
//	{
//		cout<<dis[i]<<" ";
//	}
	for(int i=fr;i<=n;i++)
	{
		if(!dis[i])
		{
			break;
		}
		g[i]+=g[i-1];
		tag[i]+=tag[i-1];
		if(dis[i]==idx-1)
		{
			continue;
		}
		g[i]=min(g[i],10000000ll);
		if(g[i]>=3)
		{
			tag[i]=1;
		}
		add(dep[dis[i]]+1,ri[i],g[i],tag[i]);
	}
	for(int i=fr+1;i<=n;i++)
	{
		ans+=(g[i]==2);
	}
}	
int c,T;
void solve()
{
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(x[i]+d>=x[mid])
			{
				l=mid+1;
				ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ri[i]=ans;
	}
	if(n<=300)
	{
		for(int i=n-1;i>=1;i--)
		{
			sol(i);
		}
		printf("%lld\n",ans);
		return;
	}
	if(n<=5000)
	{
		for(int i=n-1;i>=1;i--)
		{
			sol2(i);
		}
		printf("%lld\n",ans);
		return;
	}
	printf("0\n");
}
void solve2()
{
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(x[1]+d>=x[mid])
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	ri[1]=ans;
	int z=2*ri[1]-2;
	if(z<=2)
	{
		printf("0\n");
		return;
	}
	printf("%lld\n",max(n-z+1,0ll)); 
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if(c>=11&&c<=12)
	{
		while(T--)
		{
			solve2();
		} 
		return 0;
	}
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
24 pts:硬跑拓扑序 
貌似 BIT 可以优化？？？？？？(好像不用BIT)
40 pts，有点低了 
为何不给 B 性质？？？？难道说。。。。 
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
5 2
1 2 3 4 5
*/
/*
11 1
10 22
0 7 14 21 28 35 42 49 56 63
*/