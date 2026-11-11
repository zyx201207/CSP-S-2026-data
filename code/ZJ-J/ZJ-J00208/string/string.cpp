#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct abc
{
	int a;
	char b;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].a >> a[i].b;
	}
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	int l = 1;
	int r = n;
	while(l < r)
	{
		if(a[l].b != a[r].b)
		{
			if(a[l].a < a[r].a)
			{
				ans += a[l].a;
				a[r].a -= a[l].a;
				l++;
			}
			else if(a[l].a > a[r].a)
			{
				ans += a[r].a;
				a[l].a -= a[r].a;
				r--;
			}
			else
			{
				ans += a[l].a;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].a < a[r].a)
			{
				a[r].a -= a[l].a;
				l++;
			}
			else if(a[l].a > a[r].a)
			{
				a[l].a -= a[r].a;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
