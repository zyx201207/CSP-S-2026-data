#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,D,q;
ll w[500005];
ll k[505];
//struct node{
//	ll ln,t;
//};
//vector<node>e[505];
ll mln[500005][21], mt[500005][21], idx[500005];
ll f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll aa,tt;
			cin>>aa>>tt;
			mln[aa][++idx[aa]]=i;
			mt[aa][idx[aa]]=tt;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){///floyd
			f[i][j]=1e18;
		}
	}
	for(ll i=1;i<=n;i++)f[i][i]=0;
	
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=idx[i];j++){
			for(ll k=j+1;k<=idx[i];k++){
				ll u=mln[i][j],v=mln[i][k];
				f[u][v]=f[v][u]=min(f[u][v],mt[i][j]+mt[i][k]);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll mmin=1e18;
		for(ll i=1;i<=idx[x];i++){
			for(ll j=1;j<=idx[y];j++){
				mmin=min(mmin,mt[x][i]+f[mln[x][i]][mln[y][j]]+mt[y][j]);
			}
		}
		cout<<mmin+w[x]+w[y]<<'\n';
	}
	return 0;
}
