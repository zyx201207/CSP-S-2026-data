#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool fun(ll a,ll b){

	return a<b;

} 

int main(){

	freopen("crystal.in","r",stdin);

	freopen("crystal.out","w",stdout);

	ll n = 0,m=0;

	vector<ll> a,e;

	cin>>n>>m;

	for(int i=0;i<n;i++){

		ll t;

		cin>>t;

		a.push_back(t);

	}

	sort(a.begin(),a.end(),fun);

	e.push_back(0); 

	for(int i=1;i<n;i++){

		e.push_back( e[i-1] + i * ( a[i] - a[i-1] ) );

	}

	for(int i=n-1;i>=0;i--){

		if(m>=e[i]){

			cout<<i+1;

			return 0;

		}

	}

	return 0;

}


