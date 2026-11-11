#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		if(i==1)a[i]=x;
		else a[i]=a[i-1]^x;
	}
	for(int i=m;i<=n;i++)
	{
		maxn=max(maxn,a[i]-a[i-m]);
	}
	cout<<maxn;
	return 0;
}
