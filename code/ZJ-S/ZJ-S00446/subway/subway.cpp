#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5,inf=1e17;
ll C,n,m,d,q,f[N][N],w[M],ans;
vector<pair<ll,ll> >c[M];
ll x,u,v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>x;
		for(ll j=1;j<=x;j++){
			cin>>u>>v;
			c[u].push_back({i,v});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++) f[i][j]=inf;
		f[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		x=c[i].size();
		for(ll j=0;j<x;j++){
			u=c[i][j].first;
			for(ll k=j+1;k<x;k++){
				v=c[i][k].first;
				f[u][v]=min(f[u][v],c[i][j].second+c[i][k].second);
				f[v][u]=min(f[v][u],c[i][j].second+c[i][k].second);
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
		cin>>u>>v;
		ans=inf;
		for(ll i=0;i<c[u].size();i++){
			for(ll j=0;j<c[v].size();j++){
				ans=min(ans,f[c[u][i].first][c[v][j].first]+c[u][i].second+c[v][j].second);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	
	return 0;
}