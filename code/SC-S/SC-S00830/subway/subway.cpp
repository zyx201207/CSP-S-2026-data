#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+6;
int dis[N][N],dis1[N*500],sum,now;
bool vis[N],vis1[N*500];
vector<pair<int,int>> g[N];
void dij(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto it:g[x]){
			int y=it.first,w=it.second;
			if(dis[s][y]>dis[s][x]+w){
				dis[s][y]=dis[s][x]+w;
				q.push({-dis[s][y],y});
			}
		}
	}
}
void bfs(int s){
	memset(dis1,0,sizeof(dis1));
	memset(vis1,0,sizeof(vis1));
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto it:g[x]){
			int y=it.first;
			if(vis[y])continue;
			dis1[y]=dis1[x]+1;
			q.push(y);
			vis1[y]=1;
		}
	}
}
int c,n,m,d,q,z[506][N],t[506][N],a[N],k[506];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		sum+k[i]; 
		for(int j=1;j<=k[i];j++){
			cin>>z[i][j]>>t[i][j];
			if(i==1&&j==1)now=t[i][j];
			if(t[i][j]!=now)fl=0;
			for(int l=1;l<j;l++){
				g[z[i][j]].push_back({z[i][l],t[i][j]+t[i][l]});
				g[z[i][l]].push_back({z[i][j],t[i][j]+t[i][l]});
			}
		}
	}
	if(!fl||sum<=1000){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			if(dis[x][y])cout<<dis[x][y]+a[x]+a[y]<<'\n';
			else dij(x),cout<<dis[x][y]+a[x]+a[y]<<'\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			bfs(x),cout<<dis1[y]*2*x+a[x]+a[y]<<'\n';
		}
	}
	return 0;
}