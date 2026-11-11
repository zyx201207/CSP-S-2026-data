#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	long long a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long b[200005];
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			b[i]=a[i]&a[j];
		}
	}
	long long maxn=-1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>maxn)
		{
			maxn=b[i];
		}
	}
	cout<<maxn;
	return 0;
}
