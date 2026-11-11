#include <bits/stdc++.h>
using namespace std;

char c[200005];
int a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int l = 1,r = n;
	long long ans = 0;
	while(l < r)
	{
		if(a[l] == a[r])
		{
			if(c[l] != c[r])
				ans += a[r];
			l++;
			r--;
		}
		while(a[l] > a[r])
		{
			a[l] -= a[r];
			if(c[l] != c[r])
				ans += a[r];
			r--;
		}
		while(a[r] > a[l])
		{
			a[r] -= a[l];
			if(c[l] != c[r])
				ans += a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}
