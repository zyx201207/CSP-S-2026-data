#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N];
int check(int x)
{
	long long sum=0;
	for (int i=1;i<=n;i++)
	{
		if ((a[i]&x)==x)
		{
			sum++;
		}
	}
	if (sum>=m)return 1;
	else return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%lld",a+i);
	long long l=1,r=pow(2,30),mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if (check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
