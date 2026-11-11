#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,sum=0,sum1=0,maxn=1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1;
	for(int j=2;j<=n;j++)
	{
		sum=a[j]-a[j-1];
		while(sum1+sum*(j-i)>m)
		{
			sum-=a[i]-a[i-1];
			sum1-=(a[i]-a[i-1])*(j-i);
			i++;
		}
		sum1=sum*(j-i)+sum1;
		maxn=max(maxn,(long long)(j-i+1));
	}
	cout<<maxn;
	return 0;
} 