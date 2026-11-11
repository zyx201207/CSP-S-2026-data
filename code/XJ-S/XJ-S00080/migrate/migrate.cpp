#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll js(ll x1,ll x2,ll d){
	ll c=x2-x1;
	if(c>=d){
		return 0;
	}
	if(c==d){
		return pow(2,c-1);
	} 
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		vector<ll> x;
		ll n,d;
		cin>>n>>d;
		for(ll i=0;i<n;i++){
			ll t;
			cin>>t;
			x.push_back(t);
		}
		ll sum=0;
		for(ll j=0;j<x.size();j++){
			for(ll k=j+1;k<x.size();k++){
				if(js(x[j],x[k],d)==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
