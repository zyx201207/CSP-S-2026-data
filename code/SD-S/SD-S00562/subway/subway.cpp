#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=500005,M=505;
ll dis[M][M];
int n,m,d,q,cas;
ll w[N];
vector<pair<int,ll> >g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>cas>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int k,i=1;i<=n;i++){
		cin>>k;
		ll t;
		for(int j=1,pos;j<=k;j++){
			cin>>pos>>t;
			g[pos].push_back(make_pair(i,t));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].fi,v=g[i][k].fi;
				dis[u][v]=min(dis[u][v],g[i][j].se+g[i][k].se);
				dis[v][u]=min(dis[v][u],g[i][j].se+g[i][k].se);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int u,v;q;q--){
		cin>>u>>v;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(pair<int,ll> tmp1:g[u]){
			for(pair<int,ll> tmp2:g[v]){
				ans=min(ans,dis[tmp1.fi][tmp2.fi]+tmp1.se+tmp2.se);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}

