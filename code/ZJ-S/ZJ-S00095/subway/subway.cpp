#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int c /*测试点编号*/, n /*地铁线路数*/, m /*地铁站数*/, d /*每个地铁站最多被几条线路经过*/, q /*出行计划数*/;
	int w[500001] /*地铁口走到站厅*/;
	int k[501] /*经过的地铁站数*/;
	vector<int> a[501] /*第 i 条线路经过的第 j 个地铁站*/, t[501] /*从该地铁站的站厅走到第 i 条线路的站台需要的时间*/;
	vector<pair<int, int>> l[500001] /*经过第 i 个地铁站 & 对应的 j */;
	vector<int> hc[501] /* 换乘站对应的 j */;
	int x[100001], y[100001];
	class node
	{
	public:
		long long time;
		int pos, line;
		bool operator<(const node &other) const
		{
			return time < other.time;
		}
		bool operator>(const node &other) const
		{
			return time > other.time;
		}
		friend ostream &operator<<(ostream &os, const node &x)
		{
			return os << "[time = " << x.time << ", pos = " << x.pos << ", line = " << x.line << "]";
		}
	};
	ostream &operator<<(ostream &os, const pair<int, int> &x)
	{
		return os << "[first = " << x.first << ", second = " << x.second << "]";
	}
	long long bfs(const int &st, const int ed)
	{
		priority_queue<node, vector<node>, greater<node>> q;
		vector<long long> mn(m, 0x3f3f3f3f3f3f3f3f);
		{
			for (const pair<int, int> &x : l[st]) // 线路 + j
			{
				// cout << "x: " << x << '\n';
				for (const int &xx : hc[x.first]) // 换乘站 j
					if (a[x.first][xx] != st)
					{
						long long nt = (long long)t[x.first][x.second] /*到站台*/ + t[x.first][xx] /*到站厅*/;
						q.push(node{mn[a[x.first][xx]] = nt, a[x.first][xx], x.first});
					}
				auto fd = lower_bound(a[x.first].begin(), a[x.first].end(), ed);
				if (fd != a[x.first].end())
					if (*fd == ed)
						q.push(node{(long long)t[x.first][x.second] /*到站台*/ + t[x.first][fd - a[x.first].begin()] /*到站厅*/, ed, -1});
			}
		}
		while (!q.empty())
		{
			// cout << q.size() << '\n';
			node now = q.top();
			// cout << now << '\n';
			q.pop();
			if (now.pos == ed)
				return now.time + w[st] + w[ed];
			for (const pair<int, int> &x : l[now.pos]) // 线路 + j
				if (x.first != now.line)
				{
					for (const int &xx : hc[x.first]) // 换乘站 j
						if (a[x.first][xx] != now.pos)
						{
							long long nt = now.time + t[x.first][x.second] /*到站台*/ + t[x.first][xx] /*到站厅*/;
							if (nt < mn[a[x.first][xx]])
								q.push(node{mn[a[x.first][xx]] = nt, a[x.first][xx], x.first});
						}
					auto fd = lower_bound(a[x.first].begin(), a[x.first].end(), ed);
					if (fd != a[x.first].end())
						if (*fd == ed)
							q.push(node{now.time + t[x.first][x.second] /*到站台*/ + t[x.first][fd - a[x.first].begin()] /*到站厅*/, ed, -1});
				}
		}
		return -1;
	}
	int main()
	{
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++i)
			cin >> w[i];
		for (int i = 1; i <= n; ++i)
		{
			cin >> k[i];
			vector<pair<int, int>> at(k[i] + 1);
			for (int j = 1; j <= k[i]; ++j)
				cin >> at[j].first >> at[j].second;
			sort(at.begin(), at.end());
			a[i].assign(k[i] + 1, 0);
			for (int j = 1; j <= k[i]; ++j)
				a[i][j] = at[j].first;
			t[i].assign(k[i] + 1, 0);
			for (int j = 1; j <= k[i]; ++j)
				t[i][j] = at[j].second;
			for (int j = 1; j <= k[i]; ++j)
				l[a[i][j]].push_back(make_pair(i, j));
			// cout << k[i] << '\n';
		}
		for (int i = 1; i <= m; ++i)
		{
			// cout << i << ' ' << l[i].size() << '\n';
			if (l[i].size() > 1)
				for (const pair<int, int> &p : l[i])
					hc[p.first].push_back(p.second);
		}
		for (int i = 1; i <= q; ++i)
			cin >> x[i] >> y[i];
		for (int i = 1; i <= q; ++i)
			cout << bfs(x[i], y[i]) << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}
