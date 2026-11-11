#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int,int>
#define endl '\n'
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M];
vector<pii>t[M];
vector<int>belong_subway[M]; 
vector<pii>order[M];
struct edge{
	int to,w;
	int fid,tid;
	edge(int to,int w,int fid,int tid):to(to),w(w),fid(fid),tid(tid){}
};
vector<edge>g[N]; 
long long dis[N];
struct node{
	int now,w,idx;
};
struct cmp{
	const bool operator()(const node x,const node y)const{
		return x.w<y.w;
	}
};
void dijkstra(int s,int e,int so,int eo,int ts,int te){
	memset(dis,0x3f,sizeof dis);
	priority_queue<node,vector<node>,cmp>q;
	q.push({s,so});
	dis[s]=ts;
	while(!q.empty()){
		node now=q.top();q.pop();
		int u=now.now;
		int uo=now.idx;
		for(edge v:g[u]){
			int to=v.to,w=v.w,fi=v.fid,ti=v.tid;
			if(to==e&&ti>eo)continue;
			if(fi<uo)continue;
			if(dis[u]+w<dis[to]){
				dis[to]=dis[u]+w;
				q.push({to,dis[to],ti});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;cin>>a;
			int t0;cin>>t0;
			t[a].push_back(make_pair(i,t0));
			order[a].push_back(make_pair(i,j));
			if(belong_subway[a].size()>=1){
				int n0=belong_subway[a].size();
				for(int ii=0;ii<n0;ii++){
					int si=belong_subway[a][ii];
					int ti,oi;
					for(int x=0;x<t[a].size();x++){
						if(t[a][x].first==si){
							ti=t[a][x].second;
							break;
						}
					}
					for(int x=0;x<order[a].size();x++){
						if(order[a][x].first==si){
							oi=order[a][x].second;
							break;
						}
					}
					g[si].push_back({i,ti+t0,oi,j});
					g[i].push_back({si,ti+t0,j,oi});
				}
			}
			belong_subway[a].push_back(i);
		}
	}
	long long ans=0;
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		bool is_same=0;
				long long add=1e18;
		for(int x=0;x<belong_subway[s].size();x++){
			for(int v:belong_subway[e]){
				if(belong_subway[s][x]==v){
					is_same=1;
					long long t0=0;
					for(int y=0;y<t[s].size();y++){
						if(t[s][y].first==v){
							t0+=t[s][y].second;
							break;
						}
					}
					for(int y=0;y<t[e].size();y++){
						if(t[e][y].first==v){
							t0+=t[e][y].second;
							break;
						}
					}
					add=min(add,t0);
				}
			}
		}
		if(is_same){
			cout<<w[s]+w[e]+add<<endl;
			continue;
		}
		for(int x=0;x<belong_subway[s].size();x++){
			for(int v:belong_subway[e]){
				int eo,so;
				int u=belong_subway[s][x];
				for(int y=0;y<order[s].size();y++){
						if(order[s][y].first==u){
							so=order[s][y].second;
							break;
						}
					}
				
				for(int y=0;y<order[e].size();y++){
						if(order[e][y].first==v){
							eo=order[e][y].second;
							break;
						}
				}
				int ts,te;
				for(int y=0;y<t[s].size();y++){
						if(t[s][y].first==u){
							ts=t[s][y].second;
							break;
						}
					}
					for(int y=0;y<t[e].size();y++){
						if(t[e][y].first==v){
							te=t[e][y].second;
							break;
						}
					}
				dijkstra(u,v,so,eo,ts,te);
				ans=min(ans,dis[v]+w[s]+w[e]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
