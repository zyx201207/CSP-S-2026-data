#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
bool check(long long mid)
{
	long long cnt = 0;
	for(int i = 2;i <= mid;i++)
	{
		cnt += (i - 1) * b[i];
	}
	if(cnt <= m)
	{
		return true;
	}
	for(int i = mid;i < n;i++)
	{
		cnt -= (a[i] - a[i - mid + 1]);
		cnt += (mid - 1) * b[i + 1];
		if(cnt <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		b[i] = a[i] - a[i-1];
	}	
	long long l = 1,r = n;
	while(l < r)
	{
		long long mid = (l + r + 1) / 2;
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
} 
