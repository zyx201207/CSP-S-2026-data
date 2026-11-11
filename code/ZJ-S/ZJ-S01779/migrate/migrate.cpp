#include <bits/stdc++.h>

using namespace std;

int n,d;
long long ans1;
int x[2000010];

void dfs(int now,int r,int goal,int tep)
{
	if (now == r)
	{
		if (goal == tep)
			ans1++;
		return ;
	}
		
	for (int i = now + 1; i <= r; i++)
	{
		if (x[i] - x[now] <= d)
			dfs(i,r,goal,tep + 1);
	}
}

void solve()
{	
	ans1 = 0;
	cin >> n >> d;
	
	for (int i = 1; i <= n; i++)
		cin >> x[i];	
	
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 3; j <= n; j++)
		{
			int cnt = 0;
			int last = i;
			for (int k = i; k <= j; k++)
			{
				if (x[k] - x[last] > d)
				{
					cnt++;
					last = k - 1;
				}
			}
			cnt++;
			
			dfs(i,j,cnt,0);
			
			if (ans1 == 2)
				ans++;
			
			ans1 = 0;
		}
	}
	
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	while (t--)
		solve();
}
