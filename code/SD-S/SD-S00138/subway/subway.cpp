#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=510;
int a[N][N],dist[N][N],t[N][N];
int w[N];
int n,m;
queue<int> q;
bool vis[N];
void spfa(int s){
	q.push(s);
	dist[s][s]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=1;i<=n;i++){
			int fl=0;
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]==u) fl=j;
			}
			if(fl==0)continue;
			
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]==u)continue;
				int v=a[i][j];
				if(dist[s][v]>dist[s][u]+t[i][fl]+t[i][j]){
					dist[s][v]=dist[s][u]+t[i][fl]+t[i][j];
					if(!vis[v]){
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++) dist[i][j]=(1ll<<62); 
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=m;i++) spfa(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
