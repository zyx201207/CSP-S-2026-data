#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> a[2000001];
int dis[2000001];
int cnt[2000001];
int x[2000001];
queue <int> q;

void lll()
{
	int n,d;
	scanf("%lld %lld",&n,&d);
	for(int i = 1;i <= n;i++)
	{
		a[i].clear();
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&x[i]);
		for(int j = i-1;j >= 1;j--)
		{
			if(x[i]-x[j] <= d)
			{
				a[i].push_back(j);
				a[j].push_back(i);
			}
			else
			{
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		while(!q.empty())
		{
			q.pop();
		}
		for(int j = 1;j <= n;j++)
		{
			dis[j] = 1e18;
			cnt[j] = 0;
		}
		dis[i] = 0;
		cnt[i] = 1;
		q.push(i);
		while(!q.empty())
		{
			int id = q.front();
			q.pop();
			for(int j = 0;j < a[id].size();j++)
			{
				int u = a[id][j];
				if(dis[u] > dis[id]+1)
				{
					dis[u] = dis[id]+1;
					q.push(u);
				}
				if(dis[u] == dis[id]+1)
				{
					cnt[u] += cnt[id];
					cnt[u] = min(cnt[u],3ll);
				}
			}
		}
		for(int j = 1;j <= n;j++)
		{
			if(cnt[j] == 2)
			{
				ans++;
			}
		}
	}
	printf("%lld\n",ans/2);
}

#undef int
int main()
{
#define int long long
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		lll();
	}
	return 0;
}
