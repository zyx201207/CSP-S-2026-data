#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
struct node{
	int v;
	ll w;
};
int c,n,m,st,q;
int w[N],len;
ll dis[550][550];
vector<node>mp[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>st>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			int a,t;
			cin>>a>>t;
			mp[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int x=1;x<=m;x++){
		for(auto i:mp[x]){
			for(auto j:mp[x]){
				if(i.v==j.v) continue;
				int u=i.v,v=j.v,w=i.w+j.w;
				dis[u][v]=dis[v][u]=w;
			}
		}
	}
	for(int l=1;l<=n;l++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ll minn=1e18;
		for(auto i:mp[x]){
			for(auto j:mp[y]){
				int u=i.v,v=j.v;
				minn=min(minn,dis[u][v]+i.w+j.w);
			}
		}
		cout<<ans+minn<<"\n";
	}
	return 0;
}

