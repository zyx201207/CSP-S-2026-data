#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
long long a[N];
char c[35];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,mid,i,L=0,ans=0,l,r;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n%2==0) mid=n/2;
	else mid=(n+1)/2;
	l=1;r=n;
	while(l<=mid)
	{
		if(c[r]==c[l])
		{
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				a[l]=0;
				l+=1;n--;
			}
			else if(a[r]<a[l])
			{
				a[l]-=a[r];
				a[r]=0;
				r-=1;n--;
			}
			else if(a[r]==a[l])
			{
				l++;r--;n-=2;
			}
		}
		else
		{
			if(a[r]<a[l])
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
			else if(a[r]==a[l])
			{
				ans+=a[l];
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

