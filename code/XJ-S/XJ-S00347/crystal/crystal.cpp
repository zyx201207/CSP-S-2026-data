#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long int n,m,a[N],b[N],ans,t;
bool fun(long long int l,long long int r,long long int t)
{
	long long int x=(m+t)/(r-l+1);
	for(int i=l;i<=r;i++)
	{
		if(a[i]>x||x<a[i])
		{
			return false;
		}
	}
	return true;
}
long long int is_same()
{
	long long int t=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]!=t)
		{
			return -1;
		}
	}
	return t;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(is_same()>=0)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]<=m&&b[i+1]>m)
			{
				cout<<i+1;
				return 0;
			}
		}
	}
	for(long long int i=1;i<=n;i++)
	{
		for(long long int j=i;j<=n;j++)
		{
			t=b[j]-b[i-1];
			for(long long int k=1;k<=m;k++)
			{
				if(fun(i,j,t))
				{
					ans=max(ans,j-i+1);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
