#include<bits/stdc++.h> 
using namespace std;
long long mx=0,mi=1000005;
long long a[1000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,z,b;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		mi=min(a[i],mi);
	}
	z=mx-mi;
	if(z%2==0)
	{
		cout<<z/2-1;
	}
	else
	{
		cout<<z/2;
	}
	return 0;
}
