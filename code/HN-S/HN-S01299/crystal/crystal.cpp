#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=1;
ll m;
ll a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		ll x=a[i+1]-a[i];
		if(x*i<=m)
			ans++,m-=x*i;
	}
	cout<<ans;
	return 0;
}
