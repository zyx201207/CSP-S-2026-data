#include<bits/stdc++.h>
using namespace std;
long long n,a[500009],m,maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(maxn<a[i] and a[j]) maxn=a[i] and a[j];
		}
	}
	cout<<maxn;
}
