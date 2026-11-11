#include <iostream>
#define int long long
using namespace std;
int c, t, n, d, x[2000005], rou[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c == 11 || c == 12)
		{
			int t = d / (x[2] - x[1]);
			if (t == 0 || t == 1)
				cout << "0" << endl;
			else
				cout << max(0LL, n - 2 * t + 1) << endl;
		}
		else if (c <= 10)
		{
			for (int i = 1; i < n - 1; i++)
			{
				int idx = 1, flag = 0;
				rou[1] = i;
				for (int j = i + 1; j <= n; j++)
				{
					if (x[j] - x[rou[idx]] > d)
						break;
					int tf = 0;
					if (idx >= 2)
					{
						if (flag == 0)
						{
							if (rou[idx] > rou[idx - 1] + 1)
							{
								int npos = rou[idx] - 1;
								if (x[j] - x[npos] <= d)
									tf = 1;
							}
							if (rou[idx] > rou[idx - 1] + 2)
							{
								int npos = rou[idx] - 2;
								if (x[j] - x[npos] <= d)
									tf = 2;
							}
						}
						else if (flag == 1)
						{
							if (rou[idx] <= rou[idx - 1] + 1)
								tf = 1;
							else 
							{
								int npos = rou[idx] - 1;
								if (x[j] - x[npos] <= d)
									tf = 2;
								else
									tf = 1;
							}
						} 
					}
					if (tf == 1)
						cnt++;
						
//					if (tf == 1)
//						cout << i << " " << j << endl;
					
					if (j != n && x[j + 1] - x[rou[idx]] > d)
					{
						idx++;
						rou[idx] = j;
						if (idx >= 3)
						{
							if (flag == 0)
							{
								if (rou[idx - 1] > rou[idx - 2] + 2)
								{
									int npos = rou[idx - 1] - 2;
									if (x[j] - x[npos] <= d)
										break;
								}
								if (rou[idx - 1] > rou[idx - 2] + 1)
								{
									int npos = rou[idx - 1] - 1;
									if (x[j] - x[npos] <= d)
										flag = 1;
								}
							}
							else
							{
								if (rou[idx - 1] > rou[idx - 2] + 1)
								{
									int npos = rou[idx - 1] - 1;
									if (x[j] - x[npos] <= d)
										break;
								}
							}
						}
					}
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}