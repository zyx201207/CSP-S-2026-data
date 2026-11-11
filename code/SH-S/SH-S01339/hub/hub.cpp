#include<bits/stdc++.h>
using namespace std;
const int MAXN=12;

bool debug=0;
int c,T;
int n,k;
vector<int> G[MAXN];
bool vis[MAXN];
int dist[MAXN][MAXN];
void dfsdist(int u,int fa,int source){
	dist[source][u]=dist[source][fa]+1;
	if(u==source) dist[u][u]=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		dfsdist(v,u,source);
	}
} 
void initdist(){
	for(int i=0;i<n;i++) dfsdist(i,i,i);
}
bool chosen(int mask,int u){
	return mask&(1<<u);
}
void dfscheck(int u,int fa,int mask){
	vis[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		if(chosen(mask,v)) dfscheck(v,u,mask);
	}
}

int getans(int mask){
	int ans=0;
	for(int i=0;i<n;i++){
		bool ci=chosen(mask,i);
		if(ci==1) continue;
		int mindist=0x3f3f3f3f;
		for(int j=0;j<n;j++){
			bool cj=chosen(mask,j);
			if((ci^cj)==0) continue;
			mindist=min(mindist,dist[i][j]);
		}
//		if(debug){
//			cerr<<"point: "<<i<<", mindist: "<<mindist;
//		}
		ans=max(ans,mindist);
	}
	return ans;
}
bool checkpos(int mask){
	int cnt1=__builtin_popcount(mask);
	if(cnt1!=k) return 0;
	int cntcc=0;
	for(int i=0;i<n;i++){
		if(!chosen(mask,i)) continue;
		if(!vis[i]){
			cntcc++;
			dfscheck(i,i,mask);
		} 
	}
	memset(vis,0,sizeof(vis));
	if(cntcc>2) return 0;
	return 1;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		memset(dist,0x3f,sizeof(dist));
		if(k==n){
			cout<<0<<endl;
			for(int i=0;i<n;i++) G[i].clear(); 
			continue;
		} 
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		initdist();
		
		int ans=0x3f3f3f3f;
		for(int mask=0;mask<(1<<n);mask++){
//			cerr<<mask<<endl;
			if(checkpos(mask)==0) continue;
//			if(chosen(mask,7) && chosen(mask,0) && chosen(mask,1) && chosen(mask,2) && chosen(mask,5) && chosen(mask,4)) debug=1;
//			else debug=0;
			ans=min(ans,getans(mask));
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++) G[i].clear(); 
	}
	return 0;
}
