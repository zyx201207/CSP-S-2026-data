#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
using namespace std;
const int N=520,M=500050,D=25,inf=1000000000000150;
int c,n,m,d,q;
int w[M]; //站点的入厅时间 
int b[M][D],t[M][D],cnt[M]; //站点的可乘线路、进站时间、线路数 
int e[N][N]; //以线路为结点建图，由于点少边多且两点间只需考虑最短边，链式前向星不如邻接表 
bool vis[N];
int pth[N][N]; 

int calc(int x) {
	priority_queue<pair<int,int>> pq;
	while(!pq.empty()) pq.pop();
	pq.push({0,x});
	int unvisited=n;
	while(unvisited) {
		pair<int,int> p=pq.top(); pq.pop();
		int val=-p.first,u=p.second;
		if(!vis[u]) {
			vis[u]=1;
			pth[x][u]=val;
			unvisited--;
		}
		for(int i=1;i<=n;i++) {
			if(e[i][u]!=inf&&!vis[i]) pq.push({-val-e[i][u],i});
		}
	}
}

int query(int x,int y) {
	int ans=inf;
	for(int i=0;i<cnt[x];i++) {
		for(int j=0;j<cnt[y];j++) {
			ans=min(ans,t[x][i]+pth[b[x][i]][b[y][j]]+t[y][j]);
//				cout<<b[x][i]<<' '<<b[y][j]<<' '<<pth[b[x][i]][b[y][j]]<<endl;
		}
	}
	return ans+w[x]+w[y];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	FILE("subway");
	//读入 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i]; //站点 
	for(int i=1;i<=n;i++) { //地铁 
		int k;
		cin>>k;
		while(k--) {
			int a;
			cin>>a;
			cin>>t[a][cnt[a]];
			b[a][cnt[a]++]=i;
		}
	}
	
	//建图 
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=inf;
	for(int i=1;i<=m;i++) {
		for(int x=0;x<cnt[i];x++) {
			for(int y=0;y<cnt[i];y++) {
				if(y==x) continue;
				e[b[i][x]][b[i][y]]=min(e[b[i][x]][b[i][y]],t[i][x]+t[i][y]);
			}
		}
	}
	
//		for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) cout<<e[i][j]<<' '; cout<<endl;} cout<<endl;
	
	//提前计算最短路 
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) pth[i][j]=inf;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) vis[j]=0;
		calc(i);
	}
	
//		for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) cout<<pth[i][j]<<' '; cout<<endl;} cout<<endl;
		
	//处理询问 
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
	
	return 0;
}

