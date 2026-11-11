#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long b;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&b);
		a[i]=b;
	}
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
}
