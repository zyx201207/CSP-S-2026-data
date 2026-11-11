#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cnt,q,ans,sum,t;
bool flag = true;
signed main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin >> n >> m;
 	for(int i = 1;i <= n;i++) cin >> a[i];
 	if(m == 0)
 	{
 		for(int i = 1;i <= n;i++)
 		{
 			if(i == 1) cnt++;
 			t = 1;
 			if(a[i] != a[1])
			{
			 	cnt = 1;
			 	t = i;
			} 
			if(a[i] == a[i - 1] && a[i] == a[t]) cnt++;
		}
		if(cnt == 1) cout << 0;
		else cout << cnt;
		return 0;
	}
	sort(a + 1,a + n + 1);
	int k = a[2] - a[1];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == i) ans++;
		if(a[i + 1] - a[i] != k && i < n) flag = false;
	}
	if(ans == n)
	{
		sum = (n - 1) * n / 2;
		cnt = n;
		int x = n - 1;
		while(m <= sum)
		{
			sum -= a[x];
			cnt--;
			x--;
		}
		cout << cnt;
		return 0;
	}
	if(flag == true && ans != n)
	{
		int b = 1;
		while(m > k * b)
		{
			m -= k * b;
			b++;
			cnt = b;
		}
		cout << cnt;
		return 0;
	}
	q = m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(q == 0) break;
			if(q < (a[j] - a[i])) continue;
			else
			{
				q -= a[j] - a[i];
				a[i] = a[j];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(i == 1) cnt++;
		if(a[i] == a[i - 1] && a[i] == a[1]) cnt++;
	}
	cout << cnt;
	return 0;
}

