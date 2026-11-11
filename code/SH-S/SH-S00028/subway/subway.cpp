#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int w[500010];
bool vis[500010];
vector<int> a[510];
vector< pair<int, int> > t[500010];
int u, v;
long long minn = 0x3f3f3f3f3f3f3f3f;

void dfs(int now, long long sum, int line)
{
	if(now == v)
	{
		for(int i = 0; i < t[v].size(); i++)
		{
			if(t[v][i].first == line)
			{
				minn = min(minn, sum + t[v][i].second);
				//cout << minn << endl;
				//cout << now << "1" << endl;
				return; 
			}
		}
	}
	if(vis[now]) return;
	vis[now] = true;
	//cout << now << " " << sum << " " << line << endl;
	int extra;
	for(int j = 0; j < t[now].size(); j++)
	{
		if(t[now][j].first == line)
		{
			extra = t[now][j].second;
			break;
		}
	}
	for(int i = 0; i < t[now].size(); i++)
	{
		int v = t[now][i].first, w = t[now][i].second;
		if(v == line)
		{
			for(int j = 0; j < a[v].size(); j++)
			{
				if(a[v][j] != now)
				{
					dfs(a[v][j], sum, v);
				}
			}
		}
		else if(v != line)
		{
			for(int j = 0; j < a[v].size(); j++)
			{
				if(a[v][j] != now)
				{
					dfs(a[v][j], sum + w + extra, v);
					//if(now == 3) cout << sum << " " << a[v][j] << endl;
				}
			}
		}
	}
	//cout << now << " ";
	vis[now] = false;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(vis, false, sizeof(vis));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		maxn = max(maxn, k);
		for(int j = 1; j <= k; j++)
		{
			int t0, t1;
			cin >> t0 >> t1;
			a[i].push_back(t0);
			t[t0].push_back(make_pair(i, t1));
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> u >> v;
		//cout << u << " " << v << endl;
		dfs(u, 0, 0);
		long long ans = w[u] + w[v] + minn;
		minn = 0x3f3f3f3f;
		cout << ans << "\n";
	}
	return 0;
}
