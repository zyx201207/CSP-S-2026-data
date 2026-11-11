#include<bits/stdc++.h>
using namespace std;
long long a[50005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//cout<<a[n];
	for(int i=n;i>=1;i--)
	{
		sum=0;
		for(int j=1;j<=i;j++)
		{
			sum+=a[j];
		}
		if(sum+m>=a[i]*i)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
