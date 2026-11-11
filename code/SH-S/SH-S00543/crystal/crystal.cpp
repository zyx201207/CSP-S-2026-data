#include <bits/stdc++.h>
using namespace std;
const int MAXN=6e5+10;
long long n;
unsigned long long m;
long long a[MAXN];
bool check(int x)
{
	unsigned long long sum=0;
	for(long long i=1;i<=x;i++)
	{
		sum+=a[x]-a[i];
	}
	return sum<=m;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=l+(r-l+1)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
}
