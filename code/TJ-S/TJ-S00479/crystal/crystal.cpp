#include <algorithm>
#include <iostream>
#include <cstdio> 
#include <map>
#define ll long long
using namespace std;

ll a[500010];
ll b[500010];
ll dn[500010];
ll dw[500010];
ll n, m, cnt;
map <ll, ll> ct;

bool check(ll t)
{
	for (ll i = 1; i <= cnt; i++)
	{
		if (ct[b[i]] + dn[i] - t < 0)
		{
			continue;
		}
		ll cur = upper_bound(dn + 1, dn + cnt + 1, ct[b[i]] + dn[i] - t) - dn;
		cur--;
		//cout << "t i cur find" << t << ' ' << i << ' ' << cur << ' ' << ct[b[i]] + dn[i] - t << '\n';
		ll cost = dw[i] - dw[cur] - dn[cur] * (b[i] - b[cur]);
		ll num = ct[b[i]] + dn[i] + dn[cur];
		if (cost <= m && num >= t)
		{
			return true;
		}
//		else if (cur > 1)
//		{
//			int dnum = min(ct[b[cur - 1]], (m - cost) / (b[i] - b[cur - 1]));
//			int dcost = (b[i] - b[cur - 1]) * dnum;
//			if (dcost + cost <= m && dnum + num >= t)
//			{
//				return true;
//			}
//		}
		//geshu
		//ct[b[i]]+dn[i]-dn[j]
		//dw[i] - dw[j] - dn[j] * (b[i] - b[j]);
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll maxn = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		ct[a[i]]++;
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + n + 1);
	ll now = maxn + 1;//long long
	for (ll i = 1; i <= n; i++)
	{
		if (a[i] != now)
		{
			cnt++;
			now = a[i];
			b[cnt] = now;
		}
	}
	for (ll i = 1; i <= cnt; i++)
	{
		dn[i] = dn[i - 1] + ct[b[i - 1]];
		//cout << dn[i] << ' '; 
	}
	//cout << '\n';
	for (ll i = 1; i <= cnt; i++)
	{
		dw[i] = dw[i - 1] + dn[i] * (b[i] - b[i - 1]);
		
		//cout << dw[i] << ' ';
	}
	//cout << '\n';
	ll l = 1, r = n, mid = (l + r) / 2;
	while (l <= r)
	{
		mid = (l + r) / 2;
		//cout << mid << '\n';
		if (check(mid))
		{
			//cout << "pass\n";
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}
//-static-libgcc
