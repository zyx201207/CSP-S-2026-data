#include <bits/stdc++.h>
using namespace std;

int w[500005], a[505][50005], k[505];
long long t[505][50005];
bool vis[500005];
int n, m, d, q;
long long minn = 1e18;
void dfs(int x, int y, int z, int xi, long long ti)
{
//	cout << x << " " << y << " " << z << " " << xi << " " << " " << ti << endl;
	if(ti >= minn)return;
	if(x == y)
	{
		minn = min(minn, ti + t[xi][z]);
		return ;
	}
	bool f = 1;
	if(z != 0 && !vis[a[xi][z + 1]])
	{
		vis[a[xi][z + 1]] = 1;
		dfs(a[xi][z + 1], y, z + 1, xi, ti);	
		vis[a[xi][z + 1]] = 0;
	}
	if(z != 0 && !vis[a[xi][z - 1]])
	{
		vis[a[xi][z - 1]] = 1;
		dfs(a[xi][z - 1], y, z - 1, xi, ti);	
		vis[a[xi][z - 1]] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i == xi)continue;
		for(int j = 1; j < k[i]; j++)
		{
			if(a[i][j] == x && !vis[a[i][j + 1]])
			{
				f = 0;
				vis[a[i][j + 1]] = 1;
				dfs(a[i][j + 1], y, j + 1, i, ti + t[xi][z] + t[i][j]);
				vis[a[i][j + 1]] = 0;
			}
		}
		for(int j = 2; j <= k[i]; j++)
		{
			if(a[i][j] == x && !vis[a[i][j - 1]])
			{
				f = 0;
				vis[a[i][j - 1]] = 1;
				dfs(a[i][j - 1], y, j - 1, i, ti + t[xi][z] + t[i][j]);
				vis[a[i][j - 1]] = 0;
			}
		}
	}
	if(f)return;
}

void work()
{
	cin >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
		vis[i] = 0;
	}
		
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			int x, y;
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		vis[x] = 1;
		minn = 1e18;
		dfs(x, y, 0, 0, w[x] + w[y]);
		vis[x] = 0;
		cout << minn << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c;
	work();
	return 0;
}