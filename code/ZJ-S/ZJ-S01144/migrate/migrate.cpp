#include <bits/stdc++.h>
using namespace std;

long long a[2000005];

void work()
{
	int n;
	long long d;
	cin >> n >> d;
	bool f = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])f = 0;
	}
	if(f)
	{
		if(d >= a[n] - a[1])
		{
			cout << 0 << "\n";
			return ;
		}
		long long t = a[2] - a[1];
		if(t > d)
		{
			cout << 0 << "\n";
			return ;
		}
		bool f1 = 1;
		for(int i = 3; i <= n; i++)
		{
			if(a[i] - a[i - 1] + a[i - 1] - a[i] > d)
			{
				f = 0;
				break;
			}
		}
		if(f)
		{
			cout << 0 << "\n";
			return;
		}
		long long cnt = 0;
		t = 0;
		for(int i = 2; i <= n; i++)
		{
			if(t + a[i] - a[i - 1] < d)continue;
			else 
			{
				cnt++;
				t = 0;
			}
		}
		if(t != 0)cnt++;
		long long ans = 0;
		if(cnt == 2)ans = 1;
		else ans = (cnt - 1 + cnt - 2) * (cnt - 1) / 2;
		cout << ans << "\n";
		return;
	}
	cout << 0 << "\n";
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		work();
	}
	return 0;
}