#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll ji=0;
	map<ll,ll>mp;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		while(t--){
			int zd,now;
			cin>>zd>>now;
			if(mp[zd]==0)
				mp[zd]=now;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ans+=(mp[x]+mp[y]);
		cout<<ans<<endl;
	}
	return 0;
}