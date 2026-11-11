#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int c, t, h, n, k;
int dep[N];
vector<int>mp[N];
void dfs(int u, int fa)
{	
	dep[u] = dep[fa] + 1;
	
	if(mp[u].size() == 1)mx[u] = dep[u];
	h = max(h, dep[u]);
	for(int v:mp[u])
		if(v != fa)dfs(v, u), mx[fa] = max(mx[v], mx[fa]);
}
bool check1(int maxd, int k)
{
	priority_queue<pair<int, int> >q;
	q.push(1);
}
bool check(int maxd)
{
	h = 0;
	dfs(1, 0);
	return check1(maxd, k) || check2(maxd, k);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
	
		cin >> n >> k;
		for(int i=1; i<n; i++)
		{
			int u, v;
			cin >> u >> v;
			mp[u].emplace_back(v);
			mp[v].emplace_back(u);
		}
		int l = 0, r = n+1, ans = -1;
		while(l <= r)
		{
			int mid = l+r >> 1;
			if(check(mid))ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
		for(int i=1; i<=n; i++)mp[i].clear(), dep[i] = 0, mx[i] = 0;
	}
	
	return 0;
}
 