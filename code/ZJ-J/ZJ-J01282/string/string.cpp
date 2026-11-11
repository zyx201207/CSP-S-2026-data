#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+6;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[r]>a[l])
			{
				a[r]-=a[l];
				l++;
			}
			else
				l++;r--;
		}
		else
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[r]>a[l])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				ans+=a[l];
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
