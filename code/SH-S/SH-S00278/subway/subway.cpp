#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define int long long
using namespace std;
vector< pair<int,int> >g[1500005];
int w[500005],dis[1500005];
int c,n,m,d,q;
int idx=n+m+1;
void dij(int s){
	for(int i=1;i<idx;i++)dis[i]=0x3ffffff03ffffff0;
	bool vis[502];
	deque<int>ah;
	ah.push_back(s);
	vis[s]=1;
	while(ah.size()){
		int t=ah[0];
		ah.pop_front();
		for(pair<int,int> vw:g[t]){
			int v=vw.first,w=vw.second;
			if(!vis[v]){
				ah.push_back(v);
				for(int i:ah){
					if(dis[t]+w<dis[i])dis[i]=dis[t];
				}
			}
		}
	}
}
signed main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			g[idx].push_back({u,v});
			g[u].push_back({idx,v});
			g[idx].push_back({i+m,0});
			g[i+m].push_back({idx,0});
			idx++;
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
