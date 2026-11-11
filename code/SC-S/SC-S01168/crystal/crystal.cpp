#include<bits/stdc++.h>
using namespace std;
long long a[500005],maxn;
bool l,yyy;
long long uuu;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1])
		{
			l=1;
		}
	}
	if(l==0)
	{
		if(m%n!=0)
		{
			cout<<n-1;
		}
		else
		{
			cout<<n;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2,num=0;
		for(int i=1;i<mid;i++)
		{
			num+=(a[mid]-a[i]);
		}
		if(num>m)
		{
			
			r=mid-1;
		}
		if(num<m)
		{
//			if(m-num<(a[mid+1]-a[mid])||(m-num)/mid<a[mid+1]-a[mid])
//			{
			maxn=max(maxn,mid);
//			}
			l=mid+1;
		}
		if(num==m)
		{
			while(a[mid+1]==a[mid])
			{
				mid++;
			}
			cout<<mid<<endl;
			return 0;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
/*
我真无语了这啥难题
*/