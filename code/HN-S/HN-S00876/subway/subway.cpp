#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int c = 0, m = 0, n = 0, a[N][N] = {}, t[N][N] = {}, d = 0, q = 0;
int w[N] = {}, k[N] = {};
int x[N] = {}, y[N] = {};

std::vector<int> f()
{
	return {0,1};
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//...
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	
	
	return 0;
}
