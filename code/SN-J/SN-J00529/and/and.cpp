#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000500];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxn=a[n-m+1];
	for(long long i=1;i<=m-1;i++)
	{
		maxn=(maxn&a[n-m+i+1]);
	}
	cout<<maxn;
}
