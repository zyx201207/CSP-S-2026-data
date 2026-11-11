#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[510];
int	a[500110][520];
int t[500110][520];
int vis[500010];
vector<int>v[500010];
int x,y;
void bfs(){
	memset(v,-1,sizeof(v));
	queue<int>q;
	q.push(x);
	vis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto x:v[u]){
			if(vis[x]>vis[u]+t[u][x]){
				q.push(x);
				vis[x]=vis[u]+t[u][x];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++){
			cin>>a[i][j]>>t[i][j];
			v[i].push_back(a[i][j]);
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		bfs();
		cout<<w[x]+w[y]+vis[y]<<"\n";
	}
	return 0;
}
