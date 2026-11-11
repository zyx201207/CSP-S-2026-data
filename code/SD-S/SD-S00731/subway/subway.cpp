#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,t[N],dis[N],vis[N],v[N],w[N];
vector<pair<int,int> > g[N];
void dij(int s){
	queue<int> q;
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(pair<int,int> x:g[u]){
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w)	dis[v]=dis[u]+w;	
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v[j]>>w[j];
			g[v[j]+i*m].push_back({v[j],w[j]});
			g[v[j]].push_back({v[j]+i*m,w[j]});
		}
		for(int j=2;j<=k;j++){
			g[v[j-1]+i*m].push_back({v[j]+i*m,0});
			g[v[j]+i*m].push_back({v[j-1]+i*m,0});
		}
	}
	while(q--){
		int st,fi;
		cin>>st>>fi;
		dij(st);
		cout<<dis[fi]+t[st]+t[fi]<<"\n";
	}
}
