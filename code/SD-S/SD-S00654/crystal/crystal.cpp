#include<bits/stdc++.h>
using namespace std;
int n;
long long m , a[int(5e5 + 5)];
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i = i + 1)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	if(n <= 5000)
	{
		long long ans = 0;
		for(int i = n;i >= 1;i = i - 1)
		{
			long long cnt = 0;
			for(int j = i;j >= 1;j = j - 1)
			{
				cnt = cnt + a[i] - a[j];
				if(cnt > m)
				{
					break;
				}
				else
				{
					ans = max(ans , ((long long)i) - j + 1);
				}
			}
		}
		cout << ans;	
	}
	else
	{
		long long diff = a[2] - a[1];
		long long cnt = 0;
		for(long long i = 1;i <= n;i = i + 1)
		{
			cnt = cnt + i * diff;
			if(cnt > m)
			{
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	return 0;
}
