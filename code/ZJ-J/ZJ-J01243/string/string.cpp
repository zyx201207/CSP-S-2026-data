#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],ans=0;
	char c[200001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	bool t=0;
	while(l<r)
	{
		t=0;
		if(c[l]==c[r]) t=1;
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			if(!t) ans+=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			if(!t) ans+=a[l];
			l++;
		}
		else
		{
			if(!t) ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 