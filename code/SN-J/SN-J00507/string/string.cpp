#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n, l, r, ans;
ll a[200005];
char c[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	l=1, r=n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	while (l<=r)
	{
		//cout << i << '\n';
		if (c[l]!=c[r])
		{
			if (a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
				//cout << "--" << r << "\n";
			}
			else if (a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
				//cout << "++" << l << "\n";
			}
			else if (a[l]==a[r])
			{
				ans+=a[l];
				a[l]=a[r]=0;
				l++, r--;
				//cout << "++" << l << "\n";
				//cout << "--" << r << "\n";
			}
		}
		else if(c[l]==c[r])
		{
			if (a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
				//cout << "--" << r << "\n";
			}
			else if (a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
				//cout << "++" << l << "\n";
			}
			else if (a[l]==a[r])
			{
				a[l]=a[r]=0;
				l++, r--;
				//cout << "++" << l << "\n";
				//cout << "--" << r << "\n";
			}
		}
	}
	cout << ans;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
