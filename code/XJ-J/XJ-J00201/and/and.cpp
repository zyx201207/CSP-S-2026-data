#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[20005],x=-100;
long long d(long long b,long long c)
{
	if(c==m+1)
	{
		return b;
	}
	for(int i=1;i<=n;i++)
	{
		b=max(b,(a[i]&b));
		d(b,c+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<d(a[1],1);
	return 0;
}
