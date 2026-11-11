#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],sum,mid,f[200005],ans,b[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b[i]=a[i];
		sum+=a[i];
		f[i]=f[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r)
	{
//		cout<<l<<" "<<r<<" "<<ans<<endl;
		if(a[r]>a[l])
		{
			if(c[r]!=c[l])
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(c[r]!=c[l])
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}	
	}
	cout<<ans;
	return 0;
}
/*
CJY help me no lose pts
ZHB help me no lose pts
SHY help me no lose pts
CYY help me no lose pts
WJB help me no lose pts
*/
