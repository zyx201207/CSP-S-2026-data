#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10, INF = 1000000000000000007;
int a[N], dp[N], cnt[N];
deque<int> q;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i += 1) cin >> a[i];

		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}

		bool flag = true;
		int D = a[2] - a[1];
		for (int i = 3; i <= n; i += 1) if ((a[i] - a[i - 1]) != D) flag = false;
		if (flag == true or (c == 11 or c == 12))
		{
			if (d < (2 * D)) cout << 0 << endl;
			else
			{
				int num = d / D;
				cout << max(0ll, n - (2 * num) + 1) << endl;
			}

			continue;
		}

		int ans = 0;
		for (int i = 1; i <= n; i += 1)
		{
			while (!q.empty()) q.pop_back();
			for (int j = 1; j <= n; j += 1) dp[j] = INF;
			for (int j = 1; j <= n; j += 1) cnt[j] = 0;

			dp[i] = 0; cnt[i] = 1;
			for (int j = i; j <= n; j += 1)
			{
				while (!q.empty() and abs(a[j] - a[q.front()]) > d) q.pop_front();
				for (auto idx: q)
				{
					int num = dp[idx] + 1;
					if (num < dp[j])
					{
						dp[j] = num;
						cnt[j] = cnt[idx];
					}
					else if (num == dp[j]) cnt[j] += cnt[idx];
				}
				while (!q.empty() and dp[q.back()] > dp[j]) q.pop_back();
				q.push_back(j);
			}

			for (int j = i; j <= n; j += 1) if (cnt[j] == 2) ans += 1;
		}

		cout << ans << endl;
	}
	return 0;
}
