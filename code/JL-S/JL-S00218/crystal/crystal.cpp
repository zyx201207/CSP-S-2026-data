#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0;
	long long n,m;
	cin>>n>>m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		if(a[0]<a[1])
		{
			a[0]++;
		}
		if(a[1]<a[2])
		{
			a[1]++;
		}
	}
	for(long long j=0;j<n;j++)
	{
		int l=a[0];
		if(a[j]==l)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

