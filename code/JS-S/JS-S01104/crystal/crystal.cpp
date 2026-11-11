#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<n;i++)
	{
		sum=0;
		for(long long j=0;j<i;j++)
		{
			sum+=a[i]-a[j];
		}
		if(sum>m)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
