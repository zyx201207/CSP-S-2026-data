#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,k;
	cin>>n>>k;

	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long sum=0;
	long long ans=1;
	for(long long i=2;i<=n;i++)
	{
		if(k>=(sum+(a[i]-a[i-1])*ans)) 
		{
			sum+=(a[i]-a[i-1])*ans;
			ans++;
		}
		else
		{
			cout<<ans;
			return 0;
		}
	}
	
	cout<<ans;
	return 0;
}
