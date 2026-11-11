#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
struct edge
{
	int to,nxt;
}e[N << 1];
int pre[N],tot;
void add(int u,int v)
{
	e[++tot] = {v,pre[u]};
	pre[u] = tot;
}
int c,T,n,dis[N],bj[N],dp[N],cl[N],ans,fl[N];
queue<int> q;
ll d,x[N];
void solve()
{
	scanf("%d %lld",&n,&d);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&x[i]);
		dis[i] = 1e9,fl[i] = 0,bj[i] = 0,cl[i] = 0,dp[i] = 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(x[i] + d >= x[j])
			{
				add(i,j);
				fl[j] = 1;
			}
			else
			{
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(fl[i] == 0)
		{
			q.push(i);
			dis[i] = 0,bj[i] = 1,dp[i] = 1,cl[i] = i;
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		bj[u] = 0;
		for(int i = pre[u];i;i = e[i].nxt)
		{
			int to = e[i].to;
			cl[to] = cl[u];
			if(dis[to] > dis[u] + 1)
			{
				dis[to] = dis[u] + 1;
				dp[to] = dp[u];
				if(!bj[to])
				{
					bj[to] = 1;
					q.push(to);
				}
			}
			else if(dis[to] == dis[u] + 1)
			{
				dp[to] += dp[u];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(fl[i] == 0)
		{
			dp[i] = 0;
		}
	}
	ans = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;i <= n;i++)
		{
			if((dp[j] - dp[j] == 2 || dp[j] == dp[i] * 2) && cl[i] == cl[j])
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
