// 西安市铁一中学 王正清和 SN-S00336
#include<bits/stdc++.h>
#define fir first
#define sec second
#define mkp make_pair
#define ll long long
using namespace std;
int byx, aqx = 1;

const int inf = 1000000010;
int n, k, D[110], FA[110];
vector<int> V[110];
int find(int x)
{
	return ((x == FA[x]) ? x : (FA[x] = find(FA[x])));
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void wangzqh()
{
	for (int i = 1;i <= n;i++) V[i].clear();
	cin >> n >> k;
	for (int i = 1;i < n;i++)
	{
		int u, v; cin >> u >> v;
		V[u].push_back(v); V[v].push_back(u);
	}
	
	int ans = inf;
	for (int s = 0;s < (1 << n);s++)
	{
		if (__builtin_popcount(s) > k) continue;
		for (int i = 1;i <= n;i++) FA[i] = i, D[i] = inf;
		for (int i = 1;i <= n;i++) if ((s >> (i - 1)) & 1) D[i] = 0;
		for (int i = 1;i <= n;i++) if (!D[i]) for (int j:V[i]) if (!D[j]) FA[find(i)] = find(j);	
		int tt = 0;
		for (int i = 1;i <= n;i++) if (!D[i] && (find(i) == i)) tt++;
		if (tt > 2) continue;
		queue<int> qu;
		for (int i = 1;i <= n;i++) if (!D[i]) qu.push(i);
		while (!qu.empty())
		{
			int x = qu.front(); qu.pop();
			for (int y:V[x]) if (D[y] > D[x] + 1) D[y] = D[x] + 1, qu.push(y);
		}  
		int mx = 0;
		for (int i = 1;i <= n;i++) mx = max(mx, D[i]);
		ans = min(ans, mx);  
	}
	cout << ans << "\n";
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	init();
	cin >> byx >> aqx;
	while (aqx--) wangzqh();
	return 0;
}
