#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[200005],ab[200005];
char c[200005],cb[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			a[i]=0;
			c[i]=' ';
			i--;
			n--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ab[i]=a[i];
		cb[i]=c[i];
	}
	for(int l=1,r=n;l<r;l++,r--)
	{
		if(a[l]>a[r])
		{
			if(a[r-1]>a[l]-a[r])
			{
				a[r-1]-=a[l]-a[r];
			}
			else
			{
				a[l+1]+=(a[l]-a[r]);
			}
		}
		else
		{
			if(a[l+1]>(a[r]-a[l]))
			{
				a[l+1]-=a[r]-a[l];
			}
			else
			{
				a[r-1]+=a[r]-a[l];
			}
		}
		if(c[l]!=c[r])
		{
			c[l]=c[r];
		}
	}
	long long cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=cb[i])
		{
			cnt2+=max(a[i],ab[i]);
		}
		else
		{
			cnt1+=abs(a[i]-ab[i]);
		}
	}
	cout<<cnt1/2+cnt2<<endl;
	return 0;
} 
