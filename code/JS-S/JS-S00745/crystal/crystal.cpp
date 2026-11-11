#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000005],c[1000005],b[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	bool flaga = 1,flagb = 1;
	ll sum = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i];
		a[b[i] + 500005]++;
		sum += abs(b[i]);
	}
	for(int i = -500004;i <= 500005;i++)
	{
		c[i + 500005] = c[i + 500004] + a[i + 500005];
	}
	for(int i = -500004;i <= n - 500004;i++)
	{
		if(a[i + 500005] != 1)
		{
			flaga = 0;
		}
	}
	for(int i = 2;i < n;i++)
	{
		if((b[i] - b[i - 1]) != (b[i + 1] - b[i]))
		{
			flagb = 0;
		}
	}
	if(flaga)
	{
		int cnt = 1;
		while(true)
		{
			if(m - cnt >= 0)
			{
				m -= cnt;
			}
			else
			{
				cnt--;
				cout << cnt;
			}
			cnt++;
		}
		return 0;
	}
	if(flagb)
	{
		int cnt = b[2] - b[1];
		int num = cnt;
		while(true)
		{
			if(m - cnt >= 0)
			{
				m -= cnt;
			}
			else
			{
				cnt -= num;
				cout << (cnt / num);
			}
			cnt += num;
		}
		return 0;
	}
	if(sum <= 100)
	{
		ll maxn = -1;
		for(int i = -100;i <= 100;i++)
		{
			sum = 0;
			if(a[i + 500005] != 0)
			{
				for(int j = -100;j <= i;j++)
				{
					sum += (i - j) * a[j + 500005];
				}
				if(sum > m)
				{
					break;
				}
				maxn = max(maxn,c[i + 500005]);
			}
		}
		cout << maxn;
		return 0;
	}
	ll maxx = -1;
	for(int i = -500004;i <= 500000;i++)
	{
		sum = 0;
		if(a[i + 500005] != 0)
		{
			for(int j = -500000;j <= i;j++)
			{
				sum += (i - j) * a[j + 500005];
			}
			if(sum > m)
			{
				break;
			}
			maxx = max(maxx,c[i + 500005]);
		}
	}
	cout << maxx;
	return 0;
}
