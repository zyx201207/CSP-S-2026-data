#include<bits/stdc++.h>
using namespace std;
int c,m,d,q,n,w[500005],k[505],x[100005],y[100005];
vector<pair<int,int> >e[500025];
int vis[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
int de[500025];
void di(int S,int P){
	memset(vis,0,sizeof(vis));
	memset(de,0x3f,sizeof(de));
	de[S]=w[S]+w[P];
	qu.push({de[S],S});
	while(!qu.empty()){
		int u=qu.top().first;
		int v=qu.top().second;
		qu.pop();
		if(vis[v]){
			continue;
		}
		vis[v]=1;
		for(int j=0;j<e[v].size();j++){
			int g=e[v][j].first;
			int t=e[v][j].second;
			if(de[g]>de[v]+t){
				de[g]=de[v]+t;
				qu.push({de[g],g});
			}
		}
	}
	cout<<de[P]<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			e[i+m].push_back({u,v});
			e[u].push_back({i+m,v});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		di(x[i],y[i]);
	}
	return 0;
} 