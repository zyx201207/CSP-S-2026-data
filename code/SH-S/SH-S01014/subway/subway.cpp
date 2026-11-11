#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500+10;
const int MAXM=5e5+10;
const int TMP=5e6+10;
int t[MAXN][MAXN];
int w[MAXM];
int c,n,m,d,q;
int k;
int ST,ED;
vector<int>BJG[MAXM];
struct edge{int to,W,zhanid;};
struct node{int zhanid,dis,line;};
priority_queue<node>Q;
bool operator < (node u,node v){return u.dis>v.dis;}
vector<edge>G[TMP];//G[i]:第i条线 在zhanid换乘到to用时W 
int dist[TMP]; 
void DJ(){
	for(int i=1;i<=n;i++){dist[i]=1e18;}
	for(int i=0;i<BJG[ST].size();i++){
		int u=BJG[ST][i];
		dist[u]=0;	
	}
	
	while(!Q.empty()){
		node u=Q.top();Q.pop();
		if(u.dis>dist[u.line])continue;
		for(int i=0;i<G[u.line].size();i++){
			int nxt=G[u.line][i].to;
			int cost=G[u.line][i].W;
			int name=G[u.line][i].zhanid;
			if(dist[u.line]+cost<dist[nxt]){
				dist[nxt]=dist[u.line]+cost;
				Q.push((node){name,dist[nxt],nxt});
			}
		}
	}
	
	int ans=1e18;
	for(int i=0;i<BJG[ED].size();i++){
		int u=BJG[ED][i];
		ans=min(ans,t[u][ED]+dist[u]);	
	}
	cout<<ans+w[ST]+w[ED]<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
			BJG[a].push_back(i);
		} 
	}
	
	
	for(int i=1;i<=m;i++){
		if(BJG[i].size()>=2){
			for(int j=0;j<BJG[i].size();j++){
				for(int k=0;k<BJG[i].size();k++){
					if(j==k)continue;
					int u=BJG[i][j];
					int v=BJG[i][k];
					G[u].push_back((edge){v,t[u][i]+t[v][i],i});
				}
			}
		}
	}	
	
	while(q--){
		cin>>ST>>ED;
		for(int i=0;i<BJG[ST].size();i++){
			int L=BJG[ST][i];
			Q.push((node){ST,0,L});
		}
		DJ();			
	}	
}
