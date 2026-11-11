#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pil pair<ll,ll>
const int N=1e6;
ll w[N],dis[N],vis[N];
ll c,n,m,d,q,k;
ll dp[N][2];
vector<pil>p[N];
queue<ll>g;
void dfs(ll s){
	memset(dis,0x3f3f3f3f3f,sizeof dis);
	dis[s]=0;
	g.push(s);
	while(!g.empty()){
		ll u=g.front();
		g.pop();
		for(int i=0;i<p[u].size();i++){
			ll d=p[u][i].second;
			ll v=p[u][i].first;
			if(dis[u]+d<dis[v]){
				dis[v]=dis[u]+d;
				g.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	while(n--){
		cin>>k;
		for(ll i=1;i<=k;i++){
			cin>>dp[i][1]>>dp[i][2];
		}
		for(ll i=1;i<=k;i++){
			for(ll j=i+1;j<=k;j++){
				ll u=dp[i][1];
				ll v=dp[j][1];
				ll d=dp[i][2]+dp[j][2];
				p[u].push_back({v,d});
				p[v].push_back({u,d});
			}
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		dfs(l);
		cout<<dis[r]+w[l]+w[r]<<endl;
	}
	return 0;
}
