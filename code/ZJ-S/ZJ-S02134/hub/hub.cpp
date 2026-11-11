#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll c,t;
ll n,k;
ll a[2000010];

void solve()
{
	cin>>n>>k;
	for(ll i=1;i<=n;++i)
		cin>>a[i]>>a[i];
	if((k*2)>=n) cout<<0<<endl;
	else cout<<n-(k*2)<<endl;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}