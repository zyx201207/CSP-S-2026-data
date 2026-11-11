#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+5;
ll c,n,m,d,q,ud[N],k,p[505][N];
void solve(){
	ll l,r,ans=1e8;
	bool f=false;
	cin>>l>>r;
	for(ll i=1;i<=n;i++){
		if(p[i][l]!=0&&p[i][r]!=0){
			ans=min(ans,p[i][l]+p[i][r]);
			f=1;
		}
	}
	if(f){
		cout<<ans+ud[l]+ud[r]<<"\n";
		return;
	}
	ans=ud[l]+ud[r];
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=n;i++){
		cin>>ud[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			p[i][x]=y;
		}
	}
	while(q--){
		solve();
	}
	return 0;
}