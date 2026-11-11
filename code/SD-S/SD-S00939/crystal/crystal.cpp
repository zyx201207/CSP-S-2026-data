#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans1=0,ans2=0,b[500005],c[500005];
long long x[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=b[i]*(i-1)+c[i-1];
		if(c[i]>m)
		{
			ans1=i-1;
			break;
		}
	}
	long long s=0;
	for(int i=n;i>=1;i--)
	{
		x[i]=a[n]-a[i];
		s+=x[i];
		if(s>m)
		{
			ans2=n-i;
			break;
		}
	}
	cout<<max(ans1,ans2);
	return 0;
 } 
