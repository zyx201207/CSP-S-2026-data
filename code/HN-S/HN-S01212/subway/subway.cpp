#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000+10;
const int INF=0x3f3f3f;
int dis[N],w[N],vis[N];
bool vi[N][N];
vector<pair<int,int>>g[N];
void init(){
	fill(dis+1,dis+N,INF);
	fill(vis+1,vis+N,0);
}
void dijst(int s){
	priority_queue<pair<int,int>> q_;
	vis[s]=0,dis[s]=0;
	q_.push({g[s][s].first,s});
	while(!q_.empty()){
		int u=q_.top().second,d=q_.top().first;
		q_.pop();
		for(auto v : g[u]){
			if(vis[v.second])continue;
			dis[v.second]=min(dis[v.second],dis[u]+v.first);
			vis[v.second]=1;
			q_.push({dis[v.second],v.second});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		int a[k+1],b[k+1];
		for(int j=1;j<=k;++j){
			cin>>a[j]>>b[j];
		}
		for(int i=1;i<=k;++i){
			for(int j=i;j<=k;++j){
				if(!vi[a[i]][a[j]]){
				   g[a[i]].push_back({b[i],a[j]});
				   g[a[j]].push_back({b[j],a[i]});
				   vi[a[i]][a[j]]=1;
				}
				else{
						if(b[i]<g[a[i]][a[j]].first){
						g[a[i]][a[j]].first=b[i];
				}
					if(b[j]<g[a[j]][a[i]].first){
						g[a[j]][a[i]].first=b[j];
				}	
				}
			}
		}
	}
	for(int T=1;T<=q;++T){
		init();
		int xr,yr;
		cin>>xr>>yr;
		dijst(xr);
		cout<<dis[yr]+w[xr]+w[yr]<<endl;
	}
}
