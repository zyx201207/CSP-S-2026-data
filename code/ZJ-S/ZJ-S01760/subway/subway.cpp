#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
int t[500001];
struct e{
	int v,w;
};
vector<e>g[505001];
bool vis[505001];
int dis[505001];
set<long long>q;
void dij(int s,int f){
	for(int i=1;i<=m+n;i++){
		vis[i]=0;
		dis[i]=INT_MAX;
	}
	q.insert(s);
	dis[s]=0;
	while(!q.empty()){
		int u=*q.begin();
		q.erase(q.begin());
		if(vis[u%100000]){
			continue;
		}
		for(e i:g[u%100000]){
			if(vis[i.v]){
				continue;
			}
			if(dis[i.v]>u/100000+i.w){
				dis[i.v]=u/100000+i.w;
				q.insert(dis[i.v]*100000+i.v);
			}
		}
		vis[u%100000]=1;
	}
	cout<<dis[f]+t[s]+t[f]<<"\n";
}
int main(){
	freopen("r","subway.in",stdin);
	freopen("w","subway.out",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int x,u,w;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>u>>w;
			g[u].push_back(e{m+i,w});
			g[m+i].push_back(e{u,w});
		}
	}
	while(Q--){
		int s,f;
		cin>>s>>f;
		if(s==f){
			cout<<0<<"\n";
		}
		else{
			dij(s,f);
		}
	}
}

