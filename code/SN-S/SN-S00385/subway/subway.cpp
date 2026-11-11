#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500010;

struct str
{
	int wei, len;
	const bool operator< (const str& now) const { return len > now.len; }
};
int c, n, m, d, T, w[maxn], minn[510][510], flag[510][510];
vector<str>mapp[maxn];
priority_queue<str>q;

int _min(int x, int y)
{
	if (x == -1)  return y;
	if (y == -1)  return x;
	return min(x, y);
}

void get(int now)
{
	for (int i = 0; i < mapp[now].size(); i++)  for (int j = i + 1; j < mapp[now].size(); j++)
	{
		int x=mapp[now][i].wei, y=mapp[now][j].wei, thi = mapp[now][i].len + mapp[now][j].len;
		minn[x][y] = _min(minn[x][y], thi);
		minn[y][x] = _min(minn[y][x], thi);
	}
	return;
}

void dij(int now)
{
	q.push({now, 0});
	while (!q.empty())
	{
		str thi = q.top(); q.pop();
		if (flag[now][thi.wei] != -1)  continue;
		flag[now][thi.wei] = thi.len;
		for (int i = 1; i <= n; i++)
		{
			if (flag[now][i] != -1)  continue;
			if (minn[thi.wei][i] == -1)  continue;
			q.push({i, thi.len + minn[thi.wei][i]});
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++)  cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t; cin >> a >> t;
			mapp[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)  for (int j = 1; j <= n; j++)  minn[i][j] = -1, flag[i][j] = -1;
	for (int i = 1; i <= n; i++)  minn[i][i] = 0;
	for (int i = 1; i <= m; i++)  get(i);
	for (int i = 1; i <= n; i++)  dij(i);
	while (T--)
	{
		int s, t; cin >> s >> t;
		int out = -1;
		for (int i = 0; i < mapp[s].size(); i++)  for (int j = 0; j < mapp[t].size(); j++)
		{
			int l = mapp[s][i].wei, r = mapp[t][j].wei, thi = mapp[s][i].len + mapp[t][j].len;
			if (flag[l][r] == -1)  continue;
			thi += flag[l][r];
			if (out == -1)  out = thi;
			out = min(out, thi);
		}
		out += w[s] + w[t];
		cout << out << "\n";
	}
	return 0;
}
