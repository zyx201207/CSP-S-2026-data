//But I know
//My dreams keep fading till I get old
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;

int x[N],f[N],g[5005][5005],h[5005][5005];
bool vis[N];
int n,d;
vector < int > now,nxt;

int calc(int u)
{
	for (int i = u;i <= n;i++)
		f[i] = vis[i] = 0;
	f[u] = 1;
	vis[u] = 1;
	now.clear();
	now.push_back(u);
	while (!now.empty())
	{
		int maxn = 0;
		for (auto i : now)
			maxn = max(maxn,i);
		for (auto i : now)
		{
			int j = maxn + 1;
			if (x[j] - x[i] > d) continue;
			while (j <= n && x[j] - x[i] <= d) 
			{
				f[j] += f[i];
				if (!vis[j]) nxt.push_back(j),vis[j] = 1;
				j++;
			}
		}
		now.swap(nxt);
		nxt.clear();
	}
	int ret = 0;
	for (int i = u;i <= n;i++)
		ret += (f[i] == 2);
	return ret;
}

void solve(int c)
{
	cin >> n >> d;
	for (int i = 1;i <= n;i++)
		cin >> x[i];
	if (c <= 10)
	{
		int ans = 0;
		for (int i = 1;i <= n;i++)
			ans += calc(i);
		cout << ans << endl;
	}
	if (c == 11 || c == 12)
	{
		int t = d / (x[2] - x[1]);
		if (t <= 1) cout << 0 << endl;
		else cout << max(0ll,n - 2 * t + 1) << endl;
	}
	if (c == 13 || c == 14)
	{
		int l = n + 1,r = 0;
		for (int i = 1;i <= n;i++)
			if (x[i] - x[1] <= d && x[n] - x[i] <= d)
			{
				l = min(l,i);
				r = max(r,i);
			}
		if (r - l + 1 >= 3)
		{
			cout << 0 << endl;
			return;
		}
		if (r - l + 1 == 2)
		{
			int t = r;
			while (t <= n && x[t] - x[l - 1] <= d) t++;
			cout << (l - 1) * (n - t + 1) << endl;
			return;
		}
		int ans = 0;
		int L,R;
		L = R = r + 1;
		while (R <= n && x[R] - x[l - 1] <= d) R++;
		if (l != 2)
		{
			while (L <= n && x[L] - x[l - 2] <= d) L++;
		}
		for (int i = 1;i <= l;i++)
			if (x[i] + d < x[r + 1])
			{
				ans += (R - L);
			}
			else if (r + 2 <= n)
			{
				if (x[r + 2] - x[i] > d) ans += (n - R + 1);
			}
		cout << ans << endl;
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin >> c >> t;
	for (;t > 0;t--)
		solve(c);
	return 0;
}
