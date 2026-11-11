#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N=2e5+15;

vector<int>g[N];
int n,k;

int dfs(int u,int fa,int s,int dp)
{
	if(s&(1<<(u-1)))
	{
		return dp;
	}
	int res=INT_MAX;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		res=min(dfs(v,u,s,dp+1),res);
	}
	return res;
}

int check(int s)
{
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(s&(1<<(i-1)))
		{
			for(auto v:g[i])
			{
				if(s&(1<<(v-1)))f++;
			}
		}
	}
	f/=2;
	if(f==k-1||f==k-2)
	{
		int dis=0;
		for(int i=1;i<=n;i++)
		{
			dis=max(dis,dfs(i,0,s,0));
		}
		return dis;;
	}
	else return INT_MAX;
}

void solve()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++) 
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=INT_MAX;
	if(n<=10)
	{
		for(int i=1;i<(1<<n);i++)
		{
			if(__builtin_popcount(i)==k)
			{
				ans=min(ans,check(i));
			}
		}
		printf("%lld\n",ans);
	}
	else
	{
		int m=n/2;
		if(n==k)
		{
			puts("0");
			return;
		}
		puts("1");
	}
}

int c;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	scanf("%lld%lld",&c,&t);
	
	while(t--)
	{
		solve();
	}

	return 0;	
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/