#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
int W[M],a[M],t[M];
vector<pair<int,int>>sta[M];
vector<pair<int,int>>G[M*20];

int dis[M*20],vis[M*20];
set<pair<int,int>>S; 
void dij(int root){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	S.insert(make_pair(0,root));
	dis[root]=0;
	while(S.size()){
		auto b=S.begin();
		int u=b->second;
		S.erase(b);
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:G[u]){
			int v=i.first;
			int w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				S.insert(make_pair(dis[v],v));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			sta[a[j]].emplace_back(make_pair(i,t[j]));
			if(j==1)continue;
			G[a[j]+i*m].emplace_back(make_pair(a[j-1]+i*m,0));
			G[a[j-1]+i*m].emplace_back(make_pair(a[j]+i*m,0));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto p:sta[i]){
			int lin=p.first;
			int tim=p.second;
			G[i].emplace_back(make_pair(i+lin*m,W[i]+tim));
			G[i+lin*m].emplace_back(make_pair(i,W[i]+tim));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:sta[i]){
			int linx=x.first;
			int timx=x.second;
			for(auto y:sta[i]){
				int liny=y.first;
				int timy=y.second;
				if(linx==liny)continue;
				G[i+linx*m].emplace_back(make_pair(i+liny*m,timx+timy));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
