#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],len,ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]>a[r])//r-- 
		{
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r])//l++
		{
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else//r-- l++
		{
			if(c[l]!=c[r]) ans+=a[l];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
