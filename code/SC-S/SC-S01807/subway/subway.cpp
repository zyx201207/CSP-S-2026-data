#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int M = 500005;


// O(Q) * O(M ^ 2) = O(QM^2) -> 11/25*100 = 44pts

struct Stat
{
	int id;
	ll w;
	vector<pair<int, ll>> l;
} stat[M];
struct query
{
	int x, y, id;
	ll ans;
	bool operator < (const query& oth) const { return x < oth.x; } 
} q_[100005];


int n, m, c, d, Q;
vector<pair<int, ll>> line[N];

ll dis[M];
bool vis[M];
void bfs(int s);
bool cmp_ans(query x, query y) { return x.id < y.id; }

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	ll sum = 0;
	for (int i = 1; i <= m; i++)
	{
		stat[i].id = i;
		cin >> stat[i].w;
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		sum += k;
		line[i].resize(k + 1);
		for (int j = 1; j <= k; j++)
		{
			int a;
			ll t;
			cin >> a >> t;
			line[i][j] = {a, t};
			stat[a].l.push_back({i, t});
		}
	}
	for (int i = 1, x, y; i <= Q; i++)
	{
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		q_[i] = {x, y, i, -1};
	}
	sort(q_ + 1, q_ + Q + 1);
	// 离线
	
	int lstx = -1;
	for (int i = 1; i <= Q; i++)
	{
//		cout << "\n\n\n\n\n\ni : " << i << "\n";
		query f = q_[i];
		int x = f.x, y = f.y;
		if (x == lstx)
			q_[i].ans = dis[y] + stat[x].w + stat[y].w;
		else
		{
//			cout << "start : " << x << '\n';
			bfs(x);
			lstx = x;
			q_[i].ans = dis[y] + stat[x].w + stat[y].w; 
		}
	}
	sort(q_ + 1, q_ + Q + 1, cmp_ans);
	for (int i = 1; i <= Q; i++)
		cout << q_[i].ans << '\n';
	return 0;
}

void bfs(int s)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	queue<pair<int, ll>> q;
	q.push({s, 0ll});
	vis[s] = true;
	while (!q.empty())
	{
		auto ft = q.front();
		q.pop();
		int nid = ft.first;
		ll d = ft.second;
//		cout << nid << " " << d << "\n";
		dis[nid] = min(dis[nid], d);
		for (auto i : stat[nid].l)
		{
			int lid = i.first;
			ll t = i.second;
			for (int j = 1; j < line[lid].size(); j++)
			{
				int nxt = line[lid][j].first;
				ll t_ = line[lid][j].second;
				if (nxt == nid)
					continue;
				dis[nxt] = min(dis[nxt], d + t + t_);
				if (!vis[nxt])
				{
					vis[nxt] = true;
					q.push({nxt, d + t + t_});
				}
			}
		}
	}
}