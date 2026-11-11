#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long int a[N], n, m, ncnt = 1, ans, cnt[N];
int zuida(int i)
{
	int cm = m, xans = 1;
	while(cm)
	{
		if(cm >= a[i] - a[i - ncnt] && i - ncnt > 0)
		{
			xans++;
			cm-=(a[i] - a[i - ncnt]);
			ncnt++;
		}
		else return xans;
	}
	return xans;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a, a + n + 1);
	int pian = 1, x = a[n] - a[n - 1];
	for(int i = n; i > 1; i--)
		if(a[i] - a[i - 1] != x) pian = 0;
	if(pian == 1)
	{
		ncnt = x;
		while(m >= 0)
		{
			m -= ncnt;
			ncnt += x;
			ans++;
		}
		cout << ans;
	}
	else
	{
		for(int i = n; i >= 1; i--)
		{
			ncnt = 1;
			cnt[i] = zuida(i);
		}
		for(int i = 1; i <= n; i++)
			ans = max(ans, cnt[i]);
		cout << ans;
	}
	return 0;
}
