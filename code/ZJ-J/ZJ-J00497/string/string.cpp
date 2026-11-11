#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,l,r;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		scanf("%s",&c[i]);
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else
			{
				ans+=a[r];
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

