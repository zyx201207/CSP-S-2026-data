#include<bits/stdc++.h>
using namespace std;
bool hmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200010];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,hmp);
	long long sum=a[1];
	for(long long i=2;i<=m;i++)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
