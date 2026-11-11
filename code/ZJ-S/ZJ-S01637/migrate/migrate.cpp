#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int c, t;
int n, d;
int nlist[2000000];
int best = -1, cnt = 0;

int dfs(int start, int end, int nowat, int step)
{
	
	if (nowat > end) return 0;
	if (nowat == end)
	{
		if (step < best || best == -1) 
		{
			best = step, cnt = 1;
			//cout << "UPDATE BEST" << step << endl;
		}
		else if (step == best) cnt += 1;
		return 0;
	}
	for (int i = nowat + 1; i < n; i++)
	{
		if (nlist[i] - nlist[nowat] <= d)
		{
			dfs(start, end, i ,step+1);
		}
		else
		{
			break;
		}
	}
	return 0;
}

int once()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> nlist[i];
		//cout << nlist[i] << " ";
	}
	//cout << endl;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			best = -1, cnt = 0;
			dfs(i, j, i, 0);
			if (best != -1 && cnt == 2)
			{
				ans++;
				//cout << "GET!" << i << " " << j << endl;
				//return 0;
			} 
		}
	}
	cout << ans << endl;
	return 0;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		once();
	}
	return 0;
}