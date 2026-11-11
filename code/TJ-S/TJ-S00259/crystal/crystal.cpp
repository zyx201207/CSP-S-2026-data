#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],sum=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		long long k=m,cnt=0;
		for(int j=i-1;j>=1;j--)
		{
			if(k-(a[i]-a[j]))
			{
				cnt++;
				k-=(a[i]-a[j]);
			}
			else
			{
				break;
			}
		}
		sum=max(sum,cnt);
	}
	cout<<sum;
	return 0;
}
