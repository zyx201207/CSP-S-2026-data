#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10005];
long long and(long long b,long long c)
{
	c=max(b,c);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out""w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int c=max(a[i],a[i+1]);
		cout<<c;
	}
	return 0;
}
