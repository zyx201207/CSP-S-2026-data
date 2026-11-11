#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
};
int n,vis[550],dis[550],f[550][550],c,m,d,w[500050],qq;
vector<node> g[550];
vector<node> a[500050];
queue<int> q;
void dij(long long s){
	while(!q.empty()){
		q.pop();
	}
	q.push(s);
	for(int i=1;i<=n;i++){
		vis[i]=0;
		if(f[s][i]>0){
			q.push(i);
			dis[i]=f[s][i];
		}
		else
			dis[i]=LONG_LONG_MAX;
	}
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		vis[u]=1;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			node v=g[u][i];
			if(vis[v.x])
				continue;
			if(dis[u]+v.y<dis[v.x]){
				dis[v.x]=dis[u]+v.y;
				q.push(v.x);
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[s][i]=dis[i];
		f[i][s]=dis[i];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				node u=a[i][j],v=a[i][k];
				g[u.x].push_back({v.x,u.y+v.y});
				g[v.x].push_back({u.x,u.y+v.y});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=qq;i++){
		int x,y,ans=LONG_LONG_MAX;
		cin>>x>>y;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				node u=a[x][j];
				node v=a[y][k];
				ans=min(ans,w[x]+w[y]+u.y+v.y+f[u.x][v.x]);
				//cout<<w[x]<<' '<<w[y]<<' '<<u.y<<' '<<v.y<<' '<<f[u.x][v.x]<<endl;
			}
		}
		cout<<ans<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].x<<' '<<g[i][j].y<<endl;
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<endl;
//	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
