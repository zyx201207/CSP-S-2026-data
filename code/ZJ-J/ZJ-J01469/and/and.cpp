#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,j,m,a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll base=a[n];
	for(i=2;i<=m;i++)
	{
		ll maxn=-1;
		for(j=n-i+1;j>=1;j--)
			maxn=max(maxn,base&a[j]);
		base=maxn;
		//cout<<maxn<<"\n";
	}
	cout<<base;
	return 0;
}