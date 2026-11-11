#include<bits/stdc++.h>
using namespace std;
#define N 100001
long long a[N];
unsigned long long b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	unsigned long long sum=0;
	unsigned long long cnt=0;
	for(unsigned long long i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[2]-a[1];
	for(unsigned long long i=2;i<=n;i++)
	{
	b[i]=a[i]-a[i-1];
}
for(unsigned long long i=1;i<=n;i++)
{
	sum+=b[i];
	cnt++;
	if(sum>=m)
	{
	break;
	}
}
if(sum==m)
cout<<cnt;
else if(sum>m)
{
	cout<<cnt-1;
}
	return 0;
}
