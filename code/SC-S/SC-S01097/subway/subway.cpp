# include <iostream>
# include <cstdlib>
# include <vector>
# include <unordered_map>
using namespace std;

int all[1000][1000];
int dat[1000][1000];
bool dist[1000];
int route;

int dfs(unordered_map<int, vector<int> >& connections, unordered_map<int, vector<int> >& routes, int x, int y)
{
	if (x == y)
	{
		dat[x][y] = 0;
		return 0;
	}
	int h = 2147482646;
	for (int i: routes[x])
	{
		for (int j: connections[i])
		{
			if (j == x || dat[j][y] < 2147482646 || dist[j])
			{
				continue;
			}
			dist[j] = true;
			int r = dfs(connections, routes, j, y);
			if (r + all[x][i] + all[j][i] < h)
			{
				h = r + all[x][i] + all[j][i];
			}
			dist[j] = false;
		}
	}
	dat[x][y] = min(dat[x][y], h);
	return dat[x][y];	
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> a = {};
	for (int i = 1; i <= m; i++)
	{
		int b;
		cin >> b;
		a.push_back(b);
	}
	unordered_map<int, vector<int> > connections(n);
	unordered_map<int, vector<int> > routes(m);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int alpha, t;
			cin >> alpha >> t;
			all[alpha][i] = t;
			connections[i].push_back(alpha);
			routes[alpha].push_back(i);
		}
	}
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				dat[j][k] = 2147482646;
			}
			dist[j] = false;
		}
		int ans = dfs(connections, routes, x, y);
		cout << ans + a[x - 1] + a[y - 1] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return EXIT_SUCCESS;
}