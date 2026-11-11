#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool com(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,com);
	printf("%lld",a[m]);
	return 0;
}
