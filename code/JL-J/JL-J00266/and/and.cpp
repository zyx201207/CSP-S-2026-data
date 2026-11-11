#include<bits/stdc++.h>
using namespace std;
#define N 1110100
long long a[N];
long long b[N];
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
	for(long long j=i+1;j<=n;j++)
	{
	b[i]=(a[i]&a[j]);
	}
	}
	sort(b+1,b+n+1);
	cout<<b[n];
 return 0;
}
