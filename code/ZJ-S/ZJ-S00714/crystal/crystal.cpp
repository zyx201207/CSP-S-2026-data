#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
map<ll,int> mp;
ll s[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
		mp[x]++;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	ll ans=mp[a[0]],l=0,sum=0;
	n=a.size();
	s[0]=mp[a[0]];
	for(int i=1;i<n;i++) s[i]=s[i-1]+mp[a[i]];
	for(int i=1;i<n;i++){
		sum+=i*(a[i]-a[i-1])*(s[i]-(l==0?0:s[l-1]));
		while(sum>m){
			sum-=(a[i]-a[l])*mp[a[l]];
			l++;
		}
		ans=max(ans,s[i]-(l==0?0:s[l-1]));
		//cout<<s[i]<<" "<<l<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
