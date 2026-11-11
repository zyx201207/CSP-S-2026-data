#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
	int l = 0, r = 0;
	char zi;
};
int a[200005];
int b[200005];
char c[200005];
int qie[200005];
node sum[200005];
int cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int pre = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		pre += a[i];
		b[i] = pre;
		cnt++;
		qie[i] = pre;
	}
	for (int i = 1; i <= n; i++)
	{
		qie[++cnt] = pre - qie[i];
	}
	sort(qie + 1, qie + cnt + 1);
	int qq = 0;
	for (int i = cnt; i > 0; i--)
	{
		if (qie[i] == qie[i - 1])
		{
			qie[i] = 1e18;
			qq++;
		}
	}
	sort(qie + 1, qie + cnt + 1);
	cnt -= qq;
	int idx = 1;
	for (int i = 1; i <= cnt; i++)
	{
		sum[i].l = sum[i - 1].r + 1;
		sum[i].r = qie[i];
		while (sum[i].l > b[idx]) idx++;
		sum[i].zi = c[idx];
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (sum[i].zi != sum[cnt - i + 1].zi)
		{
			ans += sum[i].r - sum[i].l + 1;
		}
	}
	cout << ans / 2;
	return 0;
}