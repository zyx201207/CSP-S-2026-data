#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[500010];
int b[110][500010],c[110][500010],k[500010];
vector<pair<int,int>> g[500010];
ll dis[500010];
struct node{
	int x;
	int step;
};
void bfs(int x,int y){
	queue<node> q;
	q.push({x,0});
	dis[x]=0;
	while(q.size()){
		node cur=q.front();
		q.pop();
		if(cur.x==y){
			cout<<dis[y]+a[x]+a[y]<<endl;
			return;
		}
		for(int i=0;i<g[cur.x].size();i++){
			if(dis[g[cur.x][i].first]>=cur.step+g[cur.x][i].second){
				dis[g[cur.x][i].first]=cur.step+g[cur.x][i].second;
				q.push({g[cur.x][i].first,cur.step+g[cur.x][i].second});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int o,n,m,d,q;
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int mn=2e9;
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j]>>c[i][j];
			g[b[i][j]].push_back({b[i][j]+i*n,c[i][j]});
			g[b[i][j]+i*n].push_back({b[i][j],c[i][j]});
			if(j>1){
				g[b[i][j]+i*n].push_back({b[i][j-1]+i*n,0});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<=n;i++){
			dis[i]=2e9;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				dis[b[i][j]+i*n]=2e9;
			}
		}
		bfs(x,y);
	}
	return 0;
}
