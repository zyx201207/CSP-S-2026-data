#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=100010;
int c,T;
int n,k,sz[N],fa[N],rt1,rt2,maxx,rtmax1,rtmax2;
bool vis[N];
vector<int > edge[N],tr1[N],tr2[N];
int dep1[N],dep2[N];
void dfs(int u,int f){
	sz[u]=1;fa[u]=f;
	for(const int& v:edge[u]){
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void Vis(int u){
	vis[u]=1;
	for(const int& v:edge[u]){
		if(v==fa[u]) continue;
		Vis(v);
	}
}
void Max(int u,int dep,int f,int k){
	maxx=max(maxx,dep);
	if(k==1){
		for(const int& v:tr1[u]){
			if(v==f) continue;
			Max(v,u,dep+1,k);
		}	
	}
	else{
		for(const int& v:tr2[u]){
			if(v==f) continue;
			Max(v,u,dep+1,k);
		}
	}
}
void solrt(){
	rtmax1=1e9,rtmax2=1e9;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		maxx=-1;
		Max(i,0,1,1);
		if(maxx<rtmax1){
			rtmax1=maxx;
			rt1=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		maxx=-1;
		Max(i,0,1,2);
		if(maxx<rtmax2){
			rtmax2=maxx;
			rt2=i;
		}
	}
}
void soldep(int u,int f,int dep,int k){
	if(k==1){
		dep1[dep]++;
		for(const int& v:tr1[u]){
			if(v==f) continue;
			soldep(v,u,dep+1,k);
		}	
	}
	else{
		dep2[dep]++;
		for(const int& v:tr2[u]){
			if(v==f) continue;
			soldep(v,u,dep+1,k);
		}
	}
}
void sol(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) edge[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	dfs(1,0);
	int ans=1e9;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++) tr1[j].clear(),tr2[i].clear(),vis[j]=0;
		Vis(i);
		for(int j=1;j<=n;j++){
			for(const int& k:edge[j]){
				if(!vis[j]&&!vis[k]){
					tr1[j].emplace_back(k);
					tr1[k].emplace_back(j);
				}
				if(vis[j]&&vis[k]){
					tr2[j].emplace_back(k);
					tr2[k].emplace_back(j);
				}
			}
		}
		solrt();
		soldep(rt1,0,1,1);
		soldep(rt2,0,1,2);
		for(int j=1;j<=rtmax1;j++) dep1[j]+=dep1[j-1]; 
		for(int j=1;j<=rtmax2;j++) dep2[j]+=dep2[j-1];
		for(int s=1;s<=k;s++){
			int d1=upper_bound(dep1+1,dep1+1+rtmax1,s)-dep1-1;
			int d2=upper_bound(dep2+1,dep2+1+rtmax2,k-s)-dep2-1;
			ans=min(ans,max(rtmax1-d1,rtmax2-d2));
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>T;
	while(T--) sol();
	return 0;
}
