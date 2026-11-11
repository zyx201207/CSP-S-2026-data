#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500005],k[500005],a[505][500005],t[505][500005],x,y;
int dist[500005];
vector<int> ve[500005],wi[500005];
struct sNode{
	int u,w;
	bool operator < (const sNode &b) const{
		return w<b.w;
	}
};
void bfs(int s){
	memset(dist,-0x3f,sizeof(dist));
	dist[s]=0;
	priority_queue<sNode> q;
	q.push
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	while(Q--){
		cin>>x>>y;
		bfs(x);
		cout<<dist[x][y]<<"\n";
	}
	return 0;
}
