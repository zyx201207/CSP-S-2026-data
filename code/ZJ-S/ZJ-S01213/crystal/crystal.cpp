#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500100],ans,s[500100];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1;
	for(ll r=1;r<=n;r++)
	{
		if(s[r]-s[l-1]+m>=a[r]*(r-l+1)) ans=max(ans,r-l+1);
		else
		{
			while(l<=r&&s[r]-s[l-1]+m<a[r]*(r-l+1)) l++;
		}
	}
	cout<<ans;
	return 0;
}
