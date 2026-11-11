#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a,b;
long long w[500009];
long long k[509];
vector<pair<long long,long long>> sks[500009];
vector<pair<long long,long long>> tu[500009];
bool vis[509];
long long dis[509][509];
long long infi = 100000000000000;
priority_queue<pair<long long,long long>> sd;
long long kiss[509][509];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i == j)
			{
				continue;
			}
			dis[i][j] = infi;
			kiss[i][j] = infi;
		}
	}
	for(long long i = 1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(long long i = 1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(long long j = 1;j<=k[i];j++)
		{
			scanf("%lld",&a);
			scanf("%lld",&b);
			for(auto kk:sks[a])
			{
				dis[i][kk.second] = min(dis[i][kk.second],kk.first+b);
				dis[kk.second][i] = min(dis[kk.second][i],kk.first+b);
			}
			sks[a].push_back({b,i});
		}
	}
	for(long long i = 1;i<=n;i++)
	{
		for(long long j = 1;j<=n;j++)
		{
			if(i == j||dis[i][j] == infi)
			{
				continue;
			}
			tu[i].push_back({dis[i][j],j});
		}
	}
	for(long long i = 1;i<=n;i++)
	{
		while(!sd.empty())
		{
			sd.pop();
		}
		sd.push({0,i});
		for(long long j = 1;j<=n;j++)
		{
			vis[j] = 0;
		}
		while(!sd.empty())
		{
			pair<long long,long long> now = sd.top();
			sd.pop();
			if(vis[now.second])
			{
				continue;
			}
			kiss[i][now.second] = -now.first;
			vis[now.second] = 1;
			for(auto j:tu[now.second])
			{
				if(vis[j.second])
				{
					continue;
				}
				sd.push({now.first-j.first,j.second});
			}
		}
	}
	for(int i = 1;i<=q;i++)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		long long ans = infi;
		for(auto pkm:sks[a])
		{
			for(auto asval:sks[b])
			{
				ans = min(ans,w[a]+w[b]+pkm.first+asval.first+kiss[pkm.second][asval.second]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}