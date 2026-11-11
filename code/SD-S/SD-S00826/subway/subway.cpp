#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=505,M=50010;
int c,n,m,d,q;
int w[M],a[N][M],t[N][M],dist[N];
vector<int> g[M];

void bfs(int s,int e){
	memset(dist,0x3f3f3f,sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s]=w[s];
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			int x=t[u][u]+t[u][v];
			if(dist[u]+x<dist[v]){
				dist[v]=dist[u]+x;
				q.push(v);
			}
		}
	} 
	cout<<dist[e]+w[e]<<'\n';
	
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			a[j][i]=a[i][j];
			t[j][i]=t[i][j];
			if(j>1){
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		bfs(s,e);
	}
	
	return 0;
}

