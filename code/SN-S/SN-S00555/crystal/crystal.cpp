#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=-999,flag=999;
	cin>>n>>m;
	long long m1=m,e=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long cha=a[2]-a[1];
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]!=cha)
		{
			flag=0;
		}
	}
	if(flag==999)
	{
		for(int i=cha;i<=a[n-1];i+=cha)
		{
			if(cha==0)
			{
				cout<<n;
				return 0;
			}
			e++;
			m1-=i;
			if(m1<0)
			{
				cout<<e;
				return 0;
			}
		}
	}
	sort(a,a+n);
	for(int k=0;k<n;k++)
	{
		for(int i=k;i<n;i++)
		{
			b[i]=0;
		}
		for(int i=k;i<n;i++)
		{
			for(int j=n-1;j>i;j--)
			{
				b[j]+=a[j]-a[i];
			}
		}
		for(int i=k;i<n;i++)
		{
			if(m<b[i])
			{
				if(sum<i-k)
				{
					sum=i-k;
					break;
				}
			}
		}
	}
	if(sum==-999)
	{
		cout<<n;
		return 0;
	}
	cout<<sum;
	return 0;
}
