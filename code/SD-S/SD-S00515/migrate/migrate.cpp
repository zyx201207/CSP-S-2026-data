#include<bits/stdc++.h>

using namespace std;

#define int long long
int c,t;

int n,d;
const int maxn = 5010;
const int inf = 1e9;
int a[maxn];

int dis[maxn],f[maxn],ans;
vector<int> G[maxn];

void sol(int st)
{
	queue<int> q;
	for(int i = 1;i <= n;i++) dis[i] = inf,f[i] = 0;
	dis[st] = 0;
	f[st] =1;
	q.push(st);
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(int v : G[u])
		{
			if(dis[v] > dis[u] + 1) 
			{
				dis[v] = dis[u] + 1;
				q.push(v);
				f[v] = f[u];
			}
			else if(dis[v] == dis[u] + 1) f[v] += f[u];
		}
	}
	
	for(int i = 1;i <= n;i++) if(f[i] == 2)
	{
//		cout << st << " " << i << endl;
		ans++;
	}
	return;
}

void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i++) G[i].clear();
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	ans = 0;
	for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) if(a[j] - a[i] <= d) G[i].push_back(j);

	for(int i = 1;i <= n;i++) sol(i);
	cout << ans << '\n';
	return;
}



signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> t;
	
//	if(c == 11 || c == 12)
//	{
//		while(t--) sol_a();
//		return 0;
//	}
//	if(c == 13 || c == 14)
//	{
//		while(t--) sol_b();
//		return 0;
//	}
	
	while(t--) solve();
	return 0;
}
