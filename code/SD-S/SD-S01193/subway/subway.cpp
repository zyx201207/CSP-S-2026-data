#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,e;
};
int c,n,m,d,q,w[500005],f[50505];
vector<node>g[500005];
int bfs(int x,int y){
	memset(f,-1,sizeof(f));
	f[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			node x=g[u][i];
			if(f[x.v]==-1||(f[x.v]>f[u]+x.e&&f[x.v]!=-1)){
				f[x.v]=f[u]+x.e;
				q.push(x.v);
			}
		}
	}
	return f[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)+w[x]+w[y]<<endl;
	}
} 
