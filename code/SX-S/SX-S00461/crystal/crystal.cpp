#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	ll a[100005];
	ll v[100005];
	bool b = 1;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (i!=1&&a[i]!=a[i-1])
			b = false;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		v[i] = a[i];
	if (b)	{cout << n; return 0;}
	vector<ll> c(n+1);
	bool d = true;
	for (int i=2;i<=n;i++)
	{
		c[i-1] = a[i] - a[i-1];
		if (c[i-1] != c[i-2] && i!=2)
			d = false;
	}
	int cha = 0;
	for (int i=1;i<n;i++)
		cha += abs(a[n] - a[i]);
	if (m >= cha)
	{
		cout << n;
		return 0;
	}
	if (d)
	{
		for (int i=2;i<=n;i++)
		{
			for (int j=1;j<i;j++)
			{
				if (m >= abs(a[i]-a[j]))
				{
					m -= abs(a[i]-a[j]);
					a[j] = a[i];
				}
				if (m <= 0)
					break;
			}
		}
		int ans = 0;
		sort(a+1,a+n+1);
		for (int i=1;i<n;i++)
		{
			if (a[i]==a[i+1])
				ans++;
		}
		cout << ++ans;
		return 0;
	}
	int ma = 0;
	for (int i=1;i<=n;i++)
	{
		ll temp = m;
		bool b1 = true;
		for (int j=i+1;j<=n;j++)
		{
			if (temp >= abs(v[j] - v[j-1]))
			{
				for (int k=j-1;k>=i;k--)
				{
					if (temp >= abs(v[j]-v[k]))
					{
						temp -= abs(v[j]-v[k]);
						v[k] = v[j];
					}
					else
					{
						b1=false;
						break;
					}
				}
				if (!b1)
					break;
			}
			else
				break;
		}
		int ans = 0;
		for (int k=2;k<=n;k++)
		{
			if (v[k] == v[k-1])
				ans++;
		}
		ma = max(ans+1,ma);
		for (int k=1;k<=n;k++)
			v[k] = a[k];
		if (i * i >= 1e8)
		{
			cout << ma;
			return 0;
		}
	}
	cout << ma;
	return 0;
}