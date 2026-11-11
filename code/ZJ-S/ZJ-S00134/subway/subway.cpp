#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e3+10; 
int c,n,m,d,q; 
int w[510]; 
int a[510][N];
int t[510][N];
int dis[510][N]; 
int vis[510][N]; 
vector<int>g[N]; 
vector<int>edge[N]; 
int x,y; 
int minn=1e18; 
void spfa(int s){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e18; 
			vis[i][j]=0; 
		}
	}
	queue<pair<int,int>>q; 
	for(int i:g[s]){
		q.push({i,s}); 
		dis[i][s]=w[s]+t[i][s];  
		vis[i][s]=1; 
	}
	while(!q.empty()){
		auto e=q.front();q.pop(); 
		int l=e.first,u=e.second; 
		vis[l][u]=0;
		if(u==y){
			minn=min(minn,dis[l][u]+t[l][u]+w[u]); 
		} 
		for(int v:edge[l]){
			if(dis[l][v]>dis[l][u]){
				dis[l][v]=dis[l][u]; 
				if(!vis[l][v]){
					vis[l][v]=1;
					q.push({l,v}); 
				}
			}
		}
		for(int line:g[u]){
			if(line==l)continue; 
			if(dis[line][u]>dis[l][u]+t[l][u]+t[line][u]){
				dis[line][u]=dis[l][u]+t[l][u]+t[line][u]; 
				if(!vis[line][u]){
					vis[line][u]=1;
					q.push({line,u}); 
				}
			}
		}
	}
}  
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i]; 
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		int y; 
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>y;
			t[i][a[i][j]]=y; 
			g[a[i][j]].push_back(i); 
			edge[i].push_back(a[i][j]); 
		}
	}
	while(q--){
		minn=1e18; 
		cin>>x>>y;
		spfa(x); 
		cout<<minn<<endl; 
	}
	return 0; 
}
