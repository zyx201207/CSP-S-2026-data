#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=505,M=5e5+5;
int c,n,m,d,q,ww[M],G[N][N];
struct node{int v,w;};
vector<node>mp[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			mp[a].pb({i,t});
		}
	}
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=n;i++) G[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=mp[i].size();
		for(int j=0;j<sz;j++)	
			for(int k=j+1;k<sz;k++){
				int u=mp[i][j].v,v=mp[i][k].v;
				int w=mp[i][j].w+mp[i][k].w;
				G[u][v]=G[v][u]=w;
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(G[i][k]!=INF&&G[k][j]!=INF)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);		
	while(q--){
		int x,y;cin>>x>>y;
		int ans=LLONG_MAX/2;
		int sz1=mp[x].size();
		int sz2=mp[y].size();
		for(auto s:mp[x])
			for(auto t:mp[y])
				if(G[s.v][t.v]!=INF)
					ans=min(ans,G[s.v][t.v]+s.w+t.w);
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
}
