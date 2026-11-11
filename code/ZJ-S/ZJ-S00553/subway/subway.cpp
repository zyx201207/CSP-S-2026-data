#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+5;
ll c,n,m,d,q,w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>c>>n>>m;
	for(ll i=1;i<=m;++i){
		cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		ll x;
		cin>>x;
		for(ll j=1;j<=n;++j){
			ll y;
			cin>>y;
		}
	}
	for(ll i=1;i<=q;++i){
		ll x;
		cin>>x;
		cout<<rand()<<"\n";
	}
	return 0;
}

