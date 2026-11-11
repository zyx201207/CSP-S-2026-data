# include <iostream>
# include <cstdlib>
# include <vector>
# include <cstring>
using namespace std;

pair<int, int> operate(vector<int>& a, vector<int>& outs, int u, int v, int d)
{
	if (u + 1 == v)
	{
		return {1, 1};
	}
	if (u == v)
	{
		return {1, 0};
	}
	int s = u + 1;
	while (a[s] - a[u] <= d && s <= v)
	{
		outs.push_back(s);
		s++;
	}
	int distance = 2147483646;
	vector<pair<int, int> > storage = {};
	for (int i: outs)
	{
		vector<int> temp = {};
		pair<int, int> result = operate(a, temp, i, v, d);
		storage.push_back(result);
		distance = min(distance, result.second);
	}
	int cnt = 0;
	for (pair<int, int> i: storage)
	{
		if (i.second == distance)
		{
			cnt += i.first;
		}
	}
	return {cnt, distance + 1};
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	for (int i = 0; i < t; i++)
	{
		int n, d;
		cin >> n >> d;
		vector<int> a(n + 1);
		for (int j = 0; j < n; j++)
		{
			int p;
			cin >> p;
			a[j + 1] = p;
		}
		int alt = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = j + 3; k <= n; k++)
			{
				vector<int> outs = {};
				pair<int, int> result = operate(a, outs, j, k, d);
				if (result.first == 2)
				{
					alt++;
				}
			}
		}
		cout << alt << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return EXIT_SUCCESS;
}