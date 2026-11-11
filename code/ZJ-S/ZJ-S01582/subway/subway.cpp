#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 510, M = 5e5 + 10;
int c;
int n, m, d, q;
int w[N];
int k[N], a[N][M], t[N][M];
vector<int> g[N], e[N];
bool st[N];
int find()
{
	for(int i = 1; i <= n; i ++)
		if(st[i])
			return i;
	return 0;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	bool flag = true;
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		if(k[i] > 2) flag = false;
		for(int j = 1; j <= k[i]; j ++)
		{
			cin >> a[i][j] >> t[i][j];
			g[j].push_back(i);
			if(g[j].size() > 1) st[j] = 1; //½»²æ´¦
			e[a[i][j]].push_back(a[i][j - 1]);
			e[a[i][j - 1]].push_back(a[i][j]);
		}
	}
	int ans = 0;
	if(n <= 2)
	{
		while(q --)
		{
			int x, y;
			cin >> x >> y;
			ans = w[x] + t[1][x] + t[1][y] + w[y];
			if(n == 1) cout << ans << endl;
			else
			{
				int u = find();
				ans += t[1][u] + t[2][u];
				cout << ans << endl;
			} 
		}
	}
	return 0;
}
