#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> PII;
const int RP = 0x3f3f3f3f;
int n, k;
const int N = 2e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int c, t;
bool st[N];
int td, length;
int dep[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int count(int x)
{
	int res = 0;
	while(x) res += x & 1, x >>= 1;
	return res;
}
void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(j == father) continue;
		dfs(j, u);
		if(dep[u] > length && st[u])
			length = dep[u], td = u;
	}
}
signed main()
{
freopen("hub.in", "r", stdin);
freopen("hub.out", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin >> c >> t;
	while(t --)
	{
		memset(h, -1, sizeof h);
		idx = 0;
		cin >> n >> k;
		int ans = 4e18;
		for(int i = 1; i < n; i ++)
		{
			int a, b;
			cin >> a >> b;
			add(a, b), add(b, a);
		}
		for(int i = 0; i < (1 << n); i ++)
			if(count(i) == k)
			{
				length = 0;
				int tmp = i;
				for(int j = 1; j <= n; j ++) st[j] = tmp & 1, tmp >>= 1;
				dfs(1, 0);
				dfs(td, 0);
				ans = min(ans, length);
			}
		cout << ans << '\n';
	}
	
	return 0;
}
