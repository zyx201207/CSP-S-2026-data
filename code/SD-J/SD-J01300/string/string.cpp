#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll ans=0;
ll sum=0;
vector<pair<ll,ll>> a;
ll t[27];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a.resize(n+1);
	for(ll i=1;i<=n;i++){
		ll in1;
		char in2;
		cin>>in1>>in2;
		a[i].first=in1;
		a[i].second=in2-'a';
		sum+=in1;
	}
	ll j=n;
	ll i=1;
	while(i<j){
		memset(t,0,sizeof(t));
		if(a[i].first<=a[j].first){
			t[a[j].second]+=a[i].first;
			a[j].first-=a[i].first;
			a[i].first=0;
		}
		else{
			t[a[j].second]+=a[j].first;
			a[i].first-=a[j].first;
			a[j].first=0;
		}
		for(ll k=0;k<27;k++){
			if(k!=a[i].second){
				ans+=t[k];
			}
		}
		if(a[j].first==0) j--;
		if(a[i].first==0) i++;
	}
	cout<<ans;
	return 0;
}
