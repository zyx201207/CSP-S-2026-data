#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII = pair<int, int>;
const int N = 1e6, Inf = 0x3f3f3f3f3f3f;
int n, d;
int x[N];
int cnt[N], dis[N];
void dfs(int dx, int step)
{
	if(dis[dx] == Inf)
	{
		dis[dx] = step;
		cnt[dx] = 1;
	}
	else if(cnt[dx] > 2) return;
	else if(dis[dx] < step) return;
	else if(dis[dx] > step) dis[dx] = step,	cnt[dx] = 1;
	else if(dis[dx] == step) cnt[dx]++;
	int idx = upper_bound(x + 1, x + 1 + n, x[dx] + d) - x - 1;
	for (int i = idx; i >= dx + 1; i--) dfs(i, step + 1);
}
void deal()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if(d == 1) cout << 0 << '\n';
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++) dis[j] = Inf, cnt[i] = 0;
		dfs(i, 0);
		int cc = 0;
		for (int j = i; j <= n; j++) if(cnt[j] == 2) cc++;
		ans += cc; 
	}
	cout << ans << '\n';
	return ;
}
signed main()
{
	cin.tie(0), cout.tie(0) -> sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) deal();
	return 0;	
} 
