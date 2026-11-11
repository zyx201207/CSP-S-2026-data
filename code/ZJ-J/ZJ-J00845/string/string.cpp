#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];

unsigned long long len,sum[200005],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	unsigned long long pos=len/2,p;
	for(int i=1;i<=n;i++)
	{
		if(sum[i+1]>=pos)
		{
			p=pos-sum[i];
			int midi=i+1;
			break;
		}
	}
	int l=1,r=n;
	while(l<=r)
	{
		int d=min(a[l],a[r]);
		if(a[l]<a[r])
		{
			a[l]=0;
			a[r]-=d;
			if(c[l]!=c[r]) ans+=d;
			l++;
		}
		else
		{
			a[r]=0;
			a[l]-=d;
			if(c[l]!=c[r]) ans+=d;
			r--;
		}	
	}
	cout<<ans;
	return 0;
}