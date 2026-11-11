#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=510,MAXM=500010,MAXD=21,MAXQ=100010;
ll c,n,m,d,q;
ll w[MAXM],k[MAXN];
vector<pair<ll,ll> >R[MAXM];
ll G[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(G,0x3f,sizeof(G));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		G[i][i]=0;
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			ll a,t;
			cin>>a>>t;
			R[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(pair<ll,ll>p1:R[i]){
			ll u=p1.first;
			for(pair<ll,ll>p2:R[i]){
				ll v=p2.first;
				ll w=p1.second+p2.second;
				G[u][v]=min(G[u][v],w);
				G[v][u]=min(G[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		ll x,y,ans=0x7f7f7f7f7f7f7f7f;
		cin>>x>>y;
		for(pair<ll,ll>p1:R[x]){
			ll u=p1.first;
			for(pair<ll,ll>p2:R[y]){
				ll v=p2.first;
				ll w=p1.second+p2.second;
				ans=min(ans,w+G[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}