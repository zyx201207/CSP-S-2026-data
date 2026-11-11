#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long maxn = 5e5 + 5;
long long a[maxn], b[maxn], ans, ans1, s[maxn], cnt;
bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i) return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (check())
	{
		for (int i = 1; i <= n; i++){
			cnt += a[i];
			if (cnt > m) break;
			ans++;
		}
		ans++;
	}
	else
	{
		b[1] = 0;
		for (int i = 2; i <= n; i++) b[i] = b[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		for (int i = 1; i <= n; i++)
		{
			if (b[i] <= m) ans = i;
			else{
				long long cnt = 1;
				while(b[i] > m){
					b[i] = b[i] - (a[i] - a[cnt]);
					cnt++;
				}
				ans1 = i - cnt + 1;
				ans = max(ans, ans1);
			}
		}
	}
	cout << ans;
	return 0;
}
