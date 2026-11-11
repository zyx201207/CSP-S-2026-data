#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]>a[r])
		{
			if(b[l]!=b[r])
				ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			if(b[l]!=b[r])
				ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(b[l]!=b[r])
				ans+=a[l];
			r--;
			l++;
		}
	}
	cout<<ans;
}
