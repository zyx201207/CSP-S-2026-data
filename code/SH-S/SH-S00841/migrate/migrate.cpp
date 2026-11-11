#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],dist[2000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ans=0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if (c <= 6)
		{
			long long path[305][305];
			memset(path,0,sizeof(path));
			for (int i = 1;i <= n;i++)
			{
				if (dist[i] > d) path[i][i+1] = 0;
				else path[i][i+1] = 1;
			}
		}
		if (c == 11 || c == 12)
		{
			dist[2] = x[2]-x[1];
			long long diff=3;
			if (dist[2] > d/2 || x[n]-x[1] <= d)
			{
				cout << 0 << "\n";
				continue;
			}
			else
			{
				for (;diff < n;diff++)
				{
					if (dist[2] > d/diff) break;
				}
				diff--;
			}
			cout << n-2*diff+1 << "\n";
		}
		if (c == 13 || c == 14)
		{
			long long s;
			for (int i = 1;i <= n;i++)
			{
				if (x[i] - x[1] > d)
				{
					s = i-1;
					break;
				}
			}
			long long t;
			for (int i = n;i >= 1;i--)
			{
				if (x[n] - x[i] > d)
				{
					t = i+1;
					break;
				}
			}
			if (t-s >= 2) cout << 0 << "\n";
			else
			{
				long long term1 = 0,term2 = 0;
				for (int i = 1;i <= s;i++)
				{
					if (x[n] - x[i] <= d)
					{
						term1 = i;
						break;
					}
				}
				for (int i = n;i >= t;i--)
				{
					if (x[i] - x[1] <= d)
					{
						term2 = i;
						break;
					}
				}
				cout << term1 * term2 << "\n";
			}
		}
	}
	return 0;
}
