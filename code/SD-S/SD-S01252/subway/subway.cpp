#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10;
const int N=6e5+10;
const int MAXN=1e18+10;
struct Node{
	int v,w;
};
struct node{
	int num,len;
};
int c,n,m,d,q,w[M];
int dis[505][505],dij[N];
vector<Node> vec[N];
vector<node> pos[M];
priority_queue<pair<int,int>> pq;
bool vis[N];
void sunrise(int s,int t){
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n+m+10;i++) dij[i]=MAXN;
	for(int i=1;i<=n+m+10;i++) vis[i]=0;
	dij[s]=0;
	for(auto i:vec[s]){
		int vv=i.v,ww=i.w;
		pq.push({-1*ww,vv});
	}
	while(!pq.empty()){
		int tp=pq.top().second;
		int dist=-1*pq.top().first;
		pq.pop();
		if(vis[tp]) continue;
		if(dij[tp]<=dist) continue;
		dij[tp]=dist;
		vis[tp]=1;
		if(tp==t) break;
		for(auto i:vec[tp]){
			int vv=i.v,ww=i.w;
			pq.push({-1*(ww+dist),vv});
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=MAXN;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			pos[a].push_back({i,t});
			vec[a].push_back({m+i,w[a]+t});
			vec[m+i].push_back({a,w[a]+t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i].size();j++){
			int numj=pos[i][j].num;
			int lenj=pos[i][j].len;
			for(int k=j+1;k<pos[i].size();k++){
				int numk=pos[i][k].num;
				int lenk=pos[i][k].len;
				dis[numj][numk]=min(dis[numj][numk],lenj+lenk);
				dis[numk][numj]=min(dis[numk][numj],lenj+lenk);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]!=MAXN){
				vec[m+i].push_back({m+j,dis[i][j]});
				vec[m+j].push_back({m+i,dis[j][i]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		sunrise(xr,yr);
		cout<<dij[yr]<<"\n";
	}
	
	
	return 0;
}
