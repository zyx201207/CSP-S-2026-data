#include <bits/stdc++.h>
using namespace std;
long long n,a[1000009];
char c[1000009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 1,r = n;
	long long ans = 0;
	while(l < r)
	{
		if (a[l] > a[r] && c[l] != c[r])
		{
			ans += a[r];
			a[l] -= a[r];
			r--;
		}
		if (a[l] < a[r] && c[l] != c[r])
		{
			ans += a[l];
			a[r] -= a[l];
			l++;
		}
		if (a[l] == a[r] && c[l] != c[r])
		{
			ans += a[l];
			l++;
			r--;
		}
		if (c[l] == c[r])
		{
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
