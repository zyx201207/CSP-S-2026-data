#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],he,h2,h3,qian[200005],hou[200005],l,r,ans;
char s;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
		b[i]=s;
		he=he+a[i];
		qian[i]=qian[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		hou[i]=hou[i+1]+a[i];
	}
	h2=he/2;
	l=1;
	r=n;
	while(l!=r)
	{
		//cout<<l<<" "<<r<<" "<<ans<<endl;
		if(b[l]!=b[r])
		{
			if(a[l]>=a[r])
			{
				ans=ans+a[r];
				a[l]=a[l]-a[r];
				r--;
			}
			else
			{
				ans=ans+a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>=a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else
			{
				a[r]=a[r]-a[l];
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 

