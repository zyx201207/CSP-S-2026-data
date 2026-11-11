#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N],sum;
char c[N];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	while (l<=r)
	{
		ll s1=a[l],s2=a[r];
		if (c[l]==c[r])
		{
			if (s1==s2)
			{
				a[l]=a[r]=0;
				l++;
				r--;
			}
			else
			{
				if (s1<s2)
				{
					a[r]-=a[l];
					a[l]=0;
					l++;
				}
				else
				{
					a[l]-=a[r];
					a[r]=0;
					r--;
				}
			}
		}
		else
		{
			if (s1==s2)
			{
				sum+=s1;
				a[l]=a[r]=0;
				l++,r--;
			}
			else if (s1<s2)
			{
				sum+=s1;
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else
			{
				sum+=s2;
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout << sum;
	return 0;
}
