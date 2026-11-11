#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[r]>a[l])
		{
			if(c[l]!=c[r])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else if(a[l]==a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}