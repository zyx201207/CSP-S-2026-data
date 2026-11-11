#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c,T,n,d,x[2000010];
ll bfs(ll s,ll t,vector<ll> *g)
{
	queue<pair<ll,ll>> q;
	q.push({0,s});
	ll cnt = 0,ans = INF;
	while(!q.empty())
	{
		ll u = q.front().second;
		ll step = q.front().first;
		q.pop();
//		cout << u << endl;
		if(u == t)
		{
			if(ans > step) ans = step,cnt = 1;
			else if(ans == step) ++cnt;
			if(cnt > 2) return -1;
			continue;
		}
		for(auto v : g[u])
		{
			if(v <= t)
			{
				q.push({step + 1,v});
			}
		}
	}
	return cnt == 2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		vector<ll> g[n + 10];
		for(ll i = 1;i <= n;i++) cin >> x[i];
		for(ll i = 1;i <= n;i++)
		{
			ll r = upper_bound(x + 1,x + n + 1,x[i] + d) - x - 1;
			for(ll j = i + 1;j <= r;j++) g[i].push_back(j);
		}
//		for(ll i = 1;i <= n;i++)
//		{
//			cout << i << ":";
//			for(auto v : g[i]) cout << v << " ";
//			cout << endl;
//		}
		ll ans = 0;
		for(ll i = 1;i <= n;i++)
		{
			for(ll j = i + 1;j <= n;j++)
			{
				if(x[j] - x[i] <= d) continue;
				if(x[j] - x[j - 1] > d) continue;
				if(bfs(i,j,g) == 1) ++ans/*,cout << i << " " << j << endl*/;
			}
//			cout << endl;
		}
		cout << ans << endl;
//		cout << ans << endl;
	}
	return 0;
}
