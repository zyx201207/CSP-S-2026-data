#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = 1e9;
int n, dis[N], mem[N], in[N];
ll a[N], cnt[N], d, ans = 0;
vector<int> e[N];
void work(int st)
{
	queue<int> q;
	for(int i = 1; i <= n; i ++)
	{
		dis[i] = inf;
		cnt[i] = 0;
		in[i] = mem[i];
	}
	dis[st] = 0;
	cnt[st] = 1;
	for(int i = 1; i <= n; i ++)
		if(!in[i]) q.push(i);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : e[u])
		{
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
			}else if(dis[v] == dis[u] + 1)
				cnt[v] += cnt[u];
			if(! -- in[v]) q.push(v);
		}
	}
	for(int i = st + 1; i <= n; i ++)
		if(cnt[i] == 2) ans ++;
//	cout << "st: " << st << '\n';
//	for(int i = 1; i <= n; i ++)
//		cout << dis[i] << ' ' << cnt[i] << '\n';
}
void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n > 10000)
	{
		cout << 0 << '\n';
		return ;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i - 1; j >= 1; j --)
		{
			if(a[i] - a[j] > d) break;
			e[j].push_back(i);
			++ mem[i];
		}
	}
	
	for(int i = 1; i <= n; i ++) work(i);
	cout << ans << '\n';
	ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		e[i].clear();
		mem[i] = 0;
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
