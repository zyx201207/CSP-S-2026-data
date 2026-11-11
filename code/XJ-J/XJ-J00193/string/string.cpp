#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],sum=0,num=0;
char x[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i]>>x[i];
		num+=a[i];
	}
	int l=1,r=n;
	for (int i = 1; ; i++)
	{
		if (l>=r)break;
		if (a[l]>a[r])
		{
			if (x[l]!=x[r])
			{
				sum+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r])
		{
			if (x[l]!=x[r])
			{
				sum+=a[r];
			}
			l++;
			r--;
		}
		else
		{
			if (x[l]!=x[r])
			{
				sum+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<sum;
	return 0;
}
