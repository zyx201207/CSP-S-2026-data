#include<bits/stdc++.h>
using namespace std;

long long num,n,a[200005],ans;
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		num += a[i];
	}
	long long l = 1,r = n,s1 = 0,s2 = 0;
	while(l <= r)
	{
		if(l == r)
		{
			break;
		}
		if(l != r)
		{
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				s1 += a[l];
				s2 += a[r];
				if(c[l] != c[r])
				{
					ans += a[r];
				}
				r--;
			}
			else if(a[l] < a[r])
			{
				a[r] -= a[l];
				s1 += a[l];
				s2 += a[r];
				if(c[l] != c[r])
				{
					ans += a[l];
				}
				l++;
			}
			else
			{
				if(c[l] != c[r])
				{
					ans += a[l];
				}
				s1 += a[l];
				s2 += a[r];
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
