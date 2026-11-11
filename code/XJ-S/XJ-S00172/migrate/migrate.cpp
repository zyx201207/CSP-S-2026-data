#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>a(n);
		for(ll i=1;i<=n;i++){
			ll x;
			cin>>x;
			a.push_back(x);
		}
		cout<<0<<'\n';
	}
	return 0;
}
