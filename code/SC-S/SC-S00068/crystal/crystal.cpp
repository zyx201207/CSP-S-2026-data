#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010];
map<ll,ll>mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m; 
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll t=a[2]-a[1];
	bool fl=1;
	for(ll i=1;i<n;i++){
		if(a[i+1]-a[i]!=t){
			fl=0;
		}
	}
	if(fl&&n>1){
		ll tt=t;
		ll ans=0;
		for(ll i=1;i<n;i++){
			//cout<<"tt------------------------------------>"<<tt<<"\n";
			if(m>=tt){
				ans=i+1;
			}else{
				break;
			}
			tt+=t*(i+1);
		}
		cout<<ans;
	}else{
		ll _=0;
		for(ll i=1;i<=n;i+=mp[a[i]]){
			ll m_=m;
			ll ans=0;
			for(ll j=i-1;j>=1;j--){
				if(m_>=a[i]-a[j]){
					m_-=a[i]-a[j];
					ans++;
				}else break;
			}
			ans+=mp[a[i]];
			_=max(_,ans); 
		}
		cout<<_;
	}
	return 0;
 }