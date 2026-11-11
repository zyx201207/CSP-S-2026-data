#include<bits/stdc++.h>
using namespace std;
bool vis[500055];
long long a[500055];
vector<pair<long long,long long> >g[500055];
long long c,n,m,d,q,ans = LLONG_MAX;
long long ck(long long x,long long y)
{
	for(pair<long long,long long>t : g[x])
	{
		if(t.first == y)return t.second;
	}
	return 0;
}
void dfs(long long x,long long y,long long sum)
{
	vis[x] = 1;
	long long t = ck(x,y);
	if(t)
	{
		ans = min(ans,sum+t);
		return;
	}
	for(pair<long long,long long>t : g[x])
	{
		if(!vis[t.first])
		{
			dfs(t.first,y,sum+t.second);
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		long long t; cin >> t;
		if(t > 2)return 0;
		if(t == 0)continue;
		if(t == 1)
		{
			long long x,y; cin >> x >> y;
			continue;
		}
		else
		{
			long long xx,yy,xy,yx;
			cin >> xx >> yy >> xy >> yx;
			g[xx].push_back({xy,yy+yx});
			g[xy].push_back({xx,yy+yx});
		}
	}
	for(long long i = 1;i <= q;i++)
	{
		long long x,y; cin >> x >> y;
		memset(vis,0,sizeof(vis));
		dfs(x,y,0); ans += a[x]+a[y];
		cout << ans << "\n";
		ans = LLONG_MAX;
	}
	return 0;
}//subway
