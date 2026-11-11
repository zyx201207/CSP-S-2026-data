#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int a[N], cnt[N], ans[N];
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i += 1) cin >> a[i];
	
	bool flag = true;
	for (int i = 2; i <= n; i += 1) if (a[i] < a[i - 1]) flag = false;
	if (flag == true)
	{
		for (int i = 1; i <= n; i += 1) ans[a[i]] = max(ans[a[i]], i);
		
		for (int i = 1; i <= m; i += 1) cout << ans[i] << " ";
		cout << endl;
		
		return 0;
	}
	
	stack<int> q;
	for (int i = 1; i <= n; i += 1)
	{
		for (int j = 1; j <= m; j += 1) cnt[j] = 0;
		for (int j = i; j <= n; j += 1)
		{
			if (cnt[a[j]] >= 1)
			{
				int p;
				do
				{
					p = q.top();
					cnt[p] -= 1; q.pop();
				}
				while (p != a[j]);
			}
			
			cnt[a[j]] += 1; q.push(a[j]);
		}
		while (!q.empty())
		{
			ans[q.top()] += 1;
			q.pop();
		}
	}
	
	for (int i = 1; i <= m; i += 1) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
