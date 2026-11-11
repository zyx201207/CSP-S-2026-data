#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, d, x[2000005], cnt[2000005], stepmin = (int)2e9;
void dfs(int now, int step, int s, int e)
{
	if(now == e)
	{
		stepmin = min(stepmin, step);
		cnt[step]++;
		return;
	}
	for(int i = now + 1; i <= e; i++)
	{
		if(x[i] - x[now] <= d) dfs(i, step + 1, s, e);
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i = 1; i <= n; i++)
		{
			cin>>x[i];
		}
		if(c == 1 || c == 2)
		{
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j = i + 1; j <= n; j++)
				{
					stepmin = (int)2e9;
					for(int i = 1; i <= n; i++) cnt[i] = 0;
					dfs(i, 0, i, j);
					if(stepmin == (int)2e9) continue;
					if(cnt[stepmin] == 2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		if(c == 13 || c == 14)
		{
			int l = x[2] - x[1]; // gongcha
			if(l >= d) cout<<0<<endl;
			else
			{
				int tmp = d / l;
//				cout<<tmp<<endl;
				int diff = tmp + (tmp - 1);
				cout<<max(0ll, n - diff)<<endl;
			}
		}
	}
	return 0;
} 
