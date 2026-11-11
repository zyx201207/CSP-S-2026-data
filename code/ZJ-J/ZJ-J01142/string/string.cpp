#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,sum,a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(1)
	{
		if(l>=r) break;
		if(c[l]==c[r])
		{
			if(a[l]==a[r]) l++,r--;
			else
			{
				if(a[l]>a[r]) a[l]-=a[r],r--;
				else a[r]-=a[l],l++;
			}
		}
		else
		{
			if(a[l]==a[r]) sum+=a[l],l++,r--;
			else
			{
				if(a[l]>a[r]) sum+=a[r],a[l]-=a[r],r--;
				else sum+=a[l],a[r]-=a[l],l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
