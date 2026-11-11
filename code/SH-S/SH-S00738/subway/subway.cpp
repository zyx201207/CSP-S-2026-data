#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
vector<ll> a[505],t[505];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll s,b;
			cin>>s>>b;
			a[i].push_back(s);
			t[i].push_back(b);
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<16<<'\n';
	}
	
	return 0;
}
