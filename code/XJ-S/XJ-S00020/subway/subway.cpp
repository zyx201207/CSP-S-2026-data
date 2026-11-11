#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5*5+200;
const int INF=1e18;
int c,n,m,d,q;
vector<pair<int,int>>g[500500];
int t[600001],a[600002],dis[600660];
bool vis[560000];
struct node{
	int x,w;
	bool operator<(const node num) const{
		return num.w<w;
	}
}; 
void dij(int s,int xxx){
	for(int i=1;i<=xxx;i++) dis[s]=INF;
	priority_queue<node>q;
	q.push({s,0});
	vis[s]=1;
	dis[s]=0;
	while(q.empty()){
		int x=q.top().x;
		if(vis[x]==1) continue;
		vis[x]=1;
		for(auto v:g[x]){
			int y=v.first;
			int z=v.second;
			if(dis[x]+dis[z]<dis[y]){
				dis[x]=dis[y]+dis[z];
				//cout<<x<<" "<<y<<endl;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		g[i].push_back({m+i,w});
	}
	int xia=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[xia+j].push_back({m+a[j],0});
			g[m+a[j]].push_back({xia+j,t[j]});
		}
		for(int j=1;j<=k;j++){
			for(int kk=1;kk<=k;kk++){
				if(j==kk) continue; 
				g[xia+j].push_back({xia+kk,t[j]});
				g[xia+kk].push_back({xia+j,t[j]});
			}
		}
		xia+=k;
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s,xia);
		cout<<dis[t]<<endl;
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/

