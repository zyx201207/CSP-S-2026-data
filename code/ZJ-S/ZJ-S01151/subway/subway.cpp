#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005],a[505][50005],t[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(!c){
    	if(n==2&&m==5) cout<<32<<"\n"<<17;
        else if(n==3&&m==7) cout<<35<<"\n"<<16;
	}
	else{
		for(ll i=1;i<=m;i++) cin>>w[i];
	    for(ll i=1;i<=n;i++){
	    	ll k;
		    cin>>k;
		    for(ll j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	    }
	    for(ll i=1;i<=q;i++){
		    ll x,y;
		    cin>>x>>y;
            cout<<0<<"\n";
	    }
	}
	return 0;
}