#include<bits/stdc++.h>
#define ll long long
const int N = 2e6 + 6;
using namespace std;
int c, T;
int n, nxt[N], pre[N];
ll d, a[N], ans;
int mnroute(int s, int t)
{
	int res = 0;
	while(s <= t)
	{
		res++;
		s = nxt[s];
		if(nxt[s] == s)
			return -1;
	}
	return res;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(n <= 3)
		{
			cout << 0 << '\n';
			continue;
		}
		if(c == 11 || c == 12)
		{
			ll gongcha = a[2] - a[1];
			if(2 * gongcha > d)
				cout << 0 << '\n';
			else
			{
				int p = (d - gongcha - 1) / gongcha;
				cout << max(n - 3 - p, 0) << '\n';
			}
			continue;
		}
		int r = 1;
		for(int i = 1; i <= n; i++)
		{
			while(r <= n && a[r] - a[i] <= d)
				r++;
			nxt[i] = r - 1;
		}
		r = n;
		for(int i = n; i >= 1; i--)
		{
			while(r >= 1 && a[i] - a[r] <= d)
				r--;
			pre[i] = r + 1;
		}
		for(int s = 1; s + 3 <= n; s++)
			for(int t = s + 3; t <= n; t++)
			{
				int p = mnroute(s, t);
				if(p == -1)
					break;
			}
		cout << ans << '\n';
	}
}
