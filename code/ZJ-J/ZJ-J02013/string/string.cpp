#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,l=1,r=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(l!=(n-r+1))
	{
		if(b[l]!=b[n-r+1])
			if(a[l]>a[n-r+1])
			{
				ans+=a[n-r+1];
				a[l]-=a[n-r+1];
				a[n-r+1]=0;
				r++;
			}
			else 
			{
				ans+=a[l];
				a[n-r+1]-=a[l];
				a[l]=0;	
				l++;
			}	
		else
			if(a[l]>a[n-r+1])
			{
				a[l]-=a[n-r+1];
				a[n-r+1]=0;
				r++;
			}
			else 
			{
				a[n-r+1]-=a[l];
				a[l]=0;	
				l++;
			}	
	}
	cout<<ans;
	return 0;
}