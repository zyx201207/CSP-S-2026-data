#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+6;
int c,n,m,d,q,w[maxn],dis[maxn][502],t[502][maxn];
bool vis[maxn][502];
struct node3{
	int v,w,d,nowd;//当前在v的地铁的第nowd的线路的站台 经过了d个不同的路线 
	bool operator < (node3 t) const{
		return w>t.w;
	};
};
vector<int>v[502];
vector<int>path[maxn]; 
priority_queue<node3>Q; 
void dij(){
	while(!Q.empty()){
		node3 now=Q.top();
		Q.pop();
		if(vis[now.v][now.nowd])continue;
		vis[now.v][now.nowd]=true;
		if(now.d<d){
			for(int i=0;i<path[now.v].size();i++){
				int v=path[now.v][i];
				if(dis[now.v][v]>dis[now.v][now.nowd]+t[now.nowd][now.v]+t[v][now.v]){
					dis[now.v][v]=dis[now.v][now.nowd]+t[now.nowd][now.v]+t[v][now.v];
					Q.push({now.v,dis[now.v][v],now.d+1,v}); 
				}
			}
		}
		for(int i=0;i<v[now.nowd].size();i++){
			int to=v[now.nowd][i];
			if(to==now.v)continue;
			if(dis[to][now.nowd]>dis[now.v][now.nowd]){
				dis[to][now.nowd]=dis[now.v][now.nowd];
				Q.push({to,dis[to][now.nowd],now.d,now.nowd});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
    	//gr[i].push_back({i+n,w[i]});
    	//gr[i+n].push_back({i,w[i]});
	}
    for(int i=1;i<=n;i++){
    	int k;
    	cin>>k;
    	int lastv,lastt;
    	for(int j=1;j<=k;j++){
    		int vv;
    		cin>>vv;
    		v[i].push_back(vv);
    		cin>>t[i][vv];
    		path[vv].push_back(i);
    		/*
    		if(j!=1){
    			gr2[lastv+n].push({i,v,t});
    			gr2[v].push_back({i,v,t});
			}else{
				
			}    		
    		lastv=v;
    		lastt=t;*/
		}
	}
	for(int i=1;i<=q;i++){
		int r1,r2;
		cin>>r1>>r2;
		int ans=1e9;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++)vis[j][k]=false;
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++)dis[j][k]=1e9;
		}
		for(int j=0;j<path[r1].size();j++){
			int v=path[r1][j];
			dis[r1][v]=w[r1]+t[v][r1];
			Q.push({r1,w[r1],1,v});
		}
		dij();
		for(int j=1;j<=n;j++)ans=min(ans,dis[r2][j]+t[j][r2]+w[r2]);
		cout<<ans<<"\n";
	}
    return 0;
}