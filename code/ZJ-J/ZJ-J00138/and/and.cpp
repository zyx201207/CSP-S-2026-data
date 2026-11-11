#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
ll n,m;
int a[MAXN],dp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2)
	{
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				dp=max(dp,(a[i] & a[j]));
		cout<<dp;
	}
	else
	{
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				for(ll k=j+1;k<=n;k++)
					dp=max(dp,(a[i] & a[j]) & a[k]);
		cout<<dp;
	}
	return 0;
}