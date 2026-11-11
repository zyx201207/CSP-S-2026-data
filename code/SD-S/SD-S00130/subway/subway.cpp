#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int mo,n,m,d,q,w[N],dist[N];
struct node {
	int a,t;
}st[N];
vector<node>G[N];
void dfs(int x,int score){
	if(x==n || G[x].size()==0){
		dist[x]=score+st[x].t+w[x];
		return;
	}
	dist[x]=score+st[x].t+w[x];
	for(int i=0;i<G[x].size();++i)dfs(G[x][i].a,G[x][i].t+score);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>mo>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++i){
			cin>>st[j].a>>st[j].t;
			G[st[j-1].a].push_back({st[j].a,st[j].t});
		}
	}
	dfs(1,0);
	for(int i=1;i<=q;++i){
		int a,b;
		cin>>a>>b;
		cout<<dist[b]-dist[a]<<'\n';
	}
	return 0;
}
