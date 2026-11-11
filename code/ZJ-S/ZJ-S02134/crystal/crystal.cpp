#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxn=500010;
ll n,m;
ll a[maxn];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
	sort(&a[1],&a[n+1]);
	ll l=1,r=1,len=1,xi=a[1];
	ll ans=0;
	while((l<=r)&&(r<=n))
	{
		if((a[r]*len-xi)>m)
		{
			--len;
			xi-=a[l];
			++l;
		}
		else
		{
			ans=max(ans,len);
			++r;
			++len;
			xi+=a[r];
		}
	}
	cout<<ans;
	return 0;
}                  