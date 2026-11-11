#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define sec second

using namespace std;

using ll = long long;
using ull =unsigned long long;
using i128 = __int128;
using p_q =priority_queue<int>;

namespace sharweek{

const int N = 114514;

vector<int> g[N];
bool is[N];
int fa[N];

int dis[N];
bool vis[N];
int q[N];
int hd=1,tl=0;

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void mian(){
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	ll ans=1e18;
	for(int s=0;s<(1<<n);s++){
		if(__builtin_popcount(s)!=k) continue;
		ll nans=-1;int ltk=k;
		for(int i=1;i<=n;i++){
			if(((s>>(i-1))&1)) is[i]=1;
			else is[i]=0;
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++){
			if(!is[i]) continue;
			for(int v:g[i]){
				if(!is[v]) continue;
				int X=find(i),Y=find(v);
				if(X==Y) continue;
				fa[X]=Y;ltk--;
			}
		}
		if(ltk>2) continue;
		for(int ss=1;ss<=n;ss++){
			int rans=1e9;
			for(int i=1;i<=n;i++) vis[i]=0,dis[i]=1e9;
			
		hd=1,tl=0;
		q[++tl]=ss;dis[ss]=0;
		while(hd<=tl){
			int u=q[hd++];
			if(is[u]){
				rans=dis[u];break;
			}
			if(vis[u]) continue;
			vis[u]=1;
			for(int v:g[u]){
				if(vis[v]) continue;
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;q[++tl]=v; 
				}
			}
		}
			nans=max(nans,1ll*rans);
		
		}
		
		ans=min(ans,nans);
	}
	cout<<ans<<"\n";
	
	for(int i=1;i<=n;i++) g[i].clear();
}

}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,_=1;
	cin>>c>>_;
	while(_-->0){
		sharweek::mian();
	}
	
	return 0;
} 
