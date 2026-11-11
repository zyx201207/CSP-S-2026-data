#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(long long i=1;i<=n;i++)
	{
		if(((arr[2]-arr[1])+(arr[i]-arr[i-1]))*(i-1)/2<=m)
		{
			sum=max(sum,i);
		}
	}
	cout<<sum;
	return 0;
}