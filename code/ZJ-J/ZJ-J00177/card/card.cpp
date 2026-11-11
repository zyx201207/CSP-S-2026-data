//CCF ±£””Œ“ AC£°£°
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

const int MAXM = 3e5 + 10;

int n;

int m;

int a[MAXN];

int vs[MAXM];

int as[MAXM];

int tmp[MAXN];

vector <pair <int, int> > g[MAXN];

void dfs (int u);

int main ()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = n; i >= 1; i--)
	{
		int tp = vs[a[i]];
		
		vs[a[i]] = i;
		
		if (!tp)
		{
			g[i + 1].push_back (make_pair (i, a[i]));
		}
		else
		{
			g[tp].push_back (make_pair (i, 0));
		}
	}
	
	dfs (n + 1);
	
	for (int i = 1; i <= m; i++)
	{
		cout << as[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}

void dfs (int u)
{
	tmp[u] = 1;
	
	for (auto to : g[u])
	{
		int tp = to.first;
		
		int w = to.second;
		
		dfs (tp);
		
		tmp[u] += tmp[tp];
		
		as[w] += tmp[tp];
	}
	
	return ;
}
