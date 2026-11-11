#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,d,q;
ll f[810][810];
ll w[500010];
void floyd(){
	for(ll k=1;k<=n+m;k++){
		for(ll i=1;i<=n+m;i++){
			for(ll j=1;j<=n+m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
}
ll main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	ll a,b;
	for(ll i=1;i<=n+m;i++){
		for(ll j=1;j<=n+m;j++){
			f[i][j]=1e9;
			if(i==j) f[i][j]=0;
		}
		
	}
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(ll j=1;j<=x;j++){
			cin>>a>>b;
			f[i][a+n]=f[a+n][i]=b;
		}
	}
	floyd();
	while(q--){
		cin>>a>>b;
		cout<<w[a]+w[b]+f[a+n][b+n]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 1 2
*/
