# include<bits/stdc++.h>
# define int long long
using namespace std;
const int MX = 2e6;
int x[MX + 10];
int n,d,c,t;
int mn,cct;
void dfs(int t,int u,int cnt)
{
	if(u == t)
	{
		if(cnt < mn)
		{
			cct = 0;
			mn = cnt;
		}
		cct += mn == cnt;
		return ;
	}
	if(cnt > mn) return ;
	for(int i = u + 1;i <= t;i++)
	{
		if(x[i] - x[u] > d) break;
		dfs(t,i,cnt + 1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		int fb = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if(n <= 9)
		{
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{
				for(int j = i;j <= n;j++)
				{
					mn = INT_MAX;
					cct = 0;
					dfs(j,i,0);
					ans+=cct == 2;
	//				cout << i << " " << j << " " << cct << endl;
				}
			}			
			cout << ans << endl;
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			fb+=(x[i] - x[1] <= d && x[n] - x[i] <= d);
		}
		if(fb)
		{
			if(fb != 2)
			{
				cout << 0 << endl;
				continue;
			}
			else
			{
				int ans = 0;
				for(int i = 1;i <= n;i++)
				{
					int itx = upper_bound(x + i,x + n + 1,x[i] + d) - x;
					ans+=n - itx + 1;
				}
				cout << ans << endl; 
			}
		}

	}
	return 0;
}
