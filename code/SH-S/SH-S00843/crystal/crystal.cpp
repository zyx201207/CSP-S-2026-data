#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
long long a[500005],dis[500005];
long long fc(int m,int n)
{
	if(m == n) return 0;
	else return fc(m,n - 1) + (n - m) * dis[n];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		dis[i] = a[i] - a[i - 1];
		if(i >= 3) f = f && dis[i] == dis[i - 1];
	}
	if(f)
	{
		long long k,x = 1;
		if(dis[2] == 0)
		{
			cout << n << endl;
			return 0;
		}
		k = m / dis[2];
		while(k >= 0 && ans < n)
		{
			k -= x;
			x++;
			ans++;
		}
		cout << ans << endl;
		return 0;
	}
	ans = 1;
	for(int i = 1;i <= n - ans;i++)
	{
		int l = i,r = n,mid = n;
		while(mid - i + 1 > ans)
		{
			mid = (l + r) / 2;
			if(fc(i,mid) > m) r = mid;
			else
			{
				ans = max(ans,mid - i + 1);
				l = mid;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
