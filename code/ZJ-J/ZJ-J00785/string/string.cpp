#include <bits/stdc++.h>
using namespace std;

const long long N = 2 * 1e5 + 5;
long long a[N], sum[N];
char c[N];
struct node{long long s; char x;} b[N], b1[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		sum[i] = a[i] + sum[i - 1];
	}
	long long ans = 0;
	for (long long i = n; i >= 1; i--)
	{
		if (sum[i - 1] <= sum[n] / 2)
		{
			ans++;
			b[ans].s = sum[i] - sum[n] / 2 - sum[n] % 2;
			b[ans].x = c[i];
			break;
		}
		ans++;
		b[ans].s = a[i];
		b[ans].x = c[i];
	}
	ans = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (sum[i] >= sum[n] / 2)
		{
			ans++;
			b1[ans].s = sum[n] / 2 - sum[i - 1];
			b1[ans].x = c[i];
			break;
		}
		ans++;
		b1[ans].s = a[i];
		b1[ans].x = c[i];
	}
	for (long long i = 1; b[i].s != 0; i++) b[i].s += b[i - 1].s;
	for (long long i = 1; b1[i].s != 0; i++) b1[i].s += b1[i - 1].s;
	ans = 0;
	long long i = 1, j = 1, cnt = 0;
	while (b[i].x != 0)
	{
		if (b[i].s == b1[j].s)
		{
			if (b[i].x != b1[j].x) ans += b[i].s - cnt;
			cnt = b[i].s;
			i++;
			j++;
		}
		else if (b[i].s > b1[j].s)
		{
			if (b[i].x != b1[j].x) ans += b1[j].s - cnt;
			cnt = b1[j].s;
			j++;
		}
		else if (b[i].s < b1[j].s)
		{
			if (b[i].x != b1[j].x) ans += b[i].s - cnt;
			cnt = b[i].s;
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
