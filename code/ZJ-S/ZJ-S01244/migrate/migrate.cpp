#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 2e6;
long long c,t,n,d,a[N+10],dis[N+10],ans,dp[N+10];
bool vis[N+10];
void solve()
{
	cin >> n >> d;
	ans = 0;
	for(int i = 1; i <= n; i++)    cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)    vis[j] = 0;
		for(int j = i; j <= n; j++)    dis[j] = INF;
		dis[i] = 0;
		queue<pair<long long,long long>> q;
		vis[i] = 1;
		q.push({i,0});
		while(!q.empty())
		{
			pair<long long,long long> cur = q.front();
			q.pop();
			for(int j = cur.first+1; j <= n; j++)
			{
				if(a[j]-a[cur.first]>d)    break;
				if(!vis[j])
				{
					dis[j] = cur.second+1;
					vis[j] = 1;
					q.push({j,dis[j]});
				}
			} 
		}
		dp[i] = 1;
		for(int j = i+1; j <= n; j++)    dp[j] = 0;
		for(int j = i+1; j <= n; j++)
		{
			for(int from = j-1; from >= i; from--)
			{
				if(a[j]-a[from]>d)    break;
				if(dis[from]+1==dis[j])    dp[j]+=dp[from];
			}
		}
		for(int j = i+1; j <= n; j++)
		{
			if(dp[j]==2)    ans++;
		}
	}
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)    solve();
	return 0;
}
