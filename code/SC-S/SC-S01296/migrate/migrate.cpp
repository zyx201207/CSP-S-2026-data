#include <bits/stdc++.h>
#define int long long
using namespace std;

int c;
struct Solution1
{
	void Solve()
	{
		int n,d;
		cin >> n >> d;
		vector<int> a(n + 1),dp(n + 1),f(n + 1),buc(n + 1,0);
		deque<int> q;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			dp[i] = 0,buc[0] = f[i] = 1;
			q.emplace_back(i);
			for(int u = i + 1;u <= n;u++)
			{
				while(!q.empty() && a[q.front()] < a[u] - d)
					buc[dp[q.front()]] -= f[q.front()],q.pop_front();
				if(q.empty())
					break;
				dp[u] = dp[q.front()] + 1,f[u] = buc[dp[u] - 1];
				ans += (f[u] == 2);
				while(!q.empty() && dp[q.back()] > dp[u])
					buc[q.back()] -= f[q.back()],q.pop_front();
				buc[dp[u]] += f[u],q.emplace_back(u);
			}
			while(!q.empty())
				buc[dp[q.back()]] -= f[q.back()],q.pop_back();
		}
		cout << ans << '\n';
	}
	Solution1()
	{
		int T;
		cin >> T;
		while(T--)
			Solve();
	}
};
struct Solution2
{
	void Solve()
	{
		int n,d;
		cin >> n >> d;
		vector<int> a(n + 1);
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		int diff = a[2] - a[1],num = d / diff;
		if(num <= 1)
			cout << "0\n";
		else
			cout << max(0ll,n - (num << 1) + 1) << '\n';
	}
	Solution2()
	{
		int T;
		cin >> T;
		while(T--)
			Solve();
	}
};
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin >> c;
	if(c == 11 || c == 12)
		Solution2();
	else
		Solution1();
}