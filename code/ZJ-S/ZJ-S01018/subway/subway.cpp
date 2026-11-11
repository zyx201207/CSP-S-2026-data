#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 20005;
int c, n, m, d, q;
int w[100005];
int t[MAXN][MAXN];
bool vis[100005];

struct node{
	int pla;
	int tim;
	
	bool operator < (const node &x)const
	{
		return tim > x.tim;
	}
};

ll solve(int sx, int sy)
{
	priority_queue<node> pq;
	pq.push({sx, 0});
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	while(pq.size())
	{
		node u = pq.top(); pq.pop();
		vis[u.pla] = true;
		if (u.pla == sy)
		{
			return w[sx] + w[sy] + u.tim;
		}
		for (int i = 1; i <= n; i++)
		{
			if (t[u.pla][i] == -1)
				continue;
			if (vis[i])
				continue;
			pq.push({i, u.tim + t[u.pla][i]});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> q;
	vector<int> tmp_pla(n + 1, 0);
	vector<int> tmp_tim(n + 1, 0);
	int len = 0;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			t[i][j] = -1;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> len;
		for (int j = 1; j <= len; j ++)
			cin >> tmp_pla[j] >> tmp_tim[j];
		for (int j = 1; j < len; j++)
		{
			for (int k = j + 1; k <= len; k++)
			{
				int pla1 = tmp_pla[j];
				int pla2 = tmp_pla[k];
				int sum = tmp_tim[j] + tmp_tim[k];
				if (t[pla1][pla2] == -1)
					t[pla1][pla2] = t[pla2][pla1] = sum;
				else
					t[pla1][pla2] = t[pla2][pla1] = min(t[pla1][pla2], sum);
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			cout << t[i][j] << ' ';
//		cout << '\n';
//	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	return 0;
}
