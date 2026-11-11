#include<bits/stdc++.h>
#pragma GCC optimie(3)
using namespace std;

typedef long long ll;
const ll MAXN=1000000000000009;
ll c,n,m,d,q;
ll w[500005] ,r1, r2;
bool visit[500005];
ll ans=MAXN;
vector<map<ll,ll>> as(505);
vector<map<ll,ll>> h(500005);
void dfs(ll u,ll line,ll goal,ll path){
	if(u==goal){
		ans=min(ans,path+as[line][u]);
		return ;
		
	}
	
	path+=as[line][u];
	for(auto i:h[u]){
		auto o=i.first;;
		for(auto p : as[o]){
			ll j=p.first;
			if(visit[j]==false){
				visit[j]=true;
				dfs(j,o,goal,path+h[u][o]);
				visit[j]=false;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;++j){
			
			ll e,r;
			cin>>e>>r;
			as[i][e]=r;
			h[e][i]=r;
		}
		
	}
	
	for(ll i=0;i<q;++i){
		ans=MAXN;
		cin>>r1>>r2;
		h[r1][0]=0;
		visit[r1]=true;
		dfs(r1,0,r2,0);
		visit[r1]=false;
		cout<<ans+w[r1]+w[r2]<<endl;
	}
	
	return 0;
}
