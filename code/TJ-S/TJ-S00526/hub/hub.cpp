#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
ll c,t,n,k,u,v;
vector<ll> tre[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<(n-k)/2;
	}
	return 0;
}

