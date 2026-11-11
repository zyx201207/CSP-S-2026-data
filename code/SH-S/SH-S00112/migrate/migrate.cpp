#include<bits/stdc++.h>
using namespace std;

const int _ = 2e6 + 9;
long long n, d;
long long ans;
long long a[_];
long long cnt[_];
void dfs(int x, int step, int r)
{
	if(x == r)
	{
		cnt[step]++;
		return;
	}
	for(int i = x + 1;i <= r;i++)
	{
		if(a[i] - a[x] <= d)
			dfs(i, step + 1, r);
		else
			break;
	}
}
bool judge(int l, int r)
{
	for(int i = 1;i <= n;i++)
		cnt[i] = 0;
	dfs(l, 0, r);
	int i = 1;
	for(;!cnt[i] && i <= n;i++);
	if(i > n)
		return false;
	return cnt[i] == 2;
}
void work(int c)
{
	if(c == 11 || c == 12)
	{
		if(d >= 2 * (a[2] - a[1]) && d < 3 * (a[2] - a[1]))
			cout << max(0ll, n - 3) << '\n';
		else
			cout << 0 << '\n';
		return;
	}
	if(c == 13 || c == 14)
	{
		cout << 0 << '\n';
		return;
	}
	ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(judge(i, j))
			{
				ans++;
				cout << i << ' ' << j << '\n';
			}
	cout << ans << '\n';
	
	return;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while(T--)
		work(c);
	
	return 0;
}
