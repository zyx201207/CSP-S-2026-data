#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5,inf=1e9;
int c,T,n,k;
struct edge{
	int u,v;
}e[N];
vector<int> G[N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int flag[N],dis[N];
int bfs(int s){
	queue<int> q;
	q.push(s);
	for(int i=0;i<n;i++) dis[i]=inf;
	dis[s]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		if(flag[x]) return dis[x];
		for(int y:G[x]){
			if(dis[y]==inf) dis[y]=dis[x]+1,q.push(y);
		}
	}
	return inf;
}
int f[N][3],d[N][2];
void dfs(int x,int fa){
	f[x][0]=f[x][1]=f[x][2]=0;
	dis[x]=0;
	d[x][0]=d[x][1]=0;
	for(int y:G[x]){
		if(y==fa) continue;
		dfs(y,x);
		dis[x]=max(dis[x],dis[y]);
		if(f[y][0]+1>f[x][0]) f[x][2]=f[x][1],f[x][1]=f[x][0],f[x][0]=f[y][0]+1;
		else if(f[y][0]+1>f[x][1]) f[x][2]=f[x][1],f[x][1]=f[y][0]+1;
		else if(f[y][0]+1>f[x][2]) f[x][2]=f[y][0]+1;
		if(dis[y]>d[x][0]) d[x][1]=d[x][0],d[x][0]=dis[y];
		else if(dis[y]>d[x][1]) d[x][1]=dis[y];
	}
	dis[x]=max(dis[x],f[x][0]+f[x][1]);
}
int g[N],dis2[N];
int ans;
void dfs2(int x,int fa){
	if(x>1) ans=min(ans,(max(dis[x],dis2[x])+1)/2);
	for(int y:G[x]){
		if(y==fa) continue;
		if(f[x][0]==f[y][0]+1){
			g[y]=max(f[x][1],g[x])+1;
			dis2[y]=max(dis2[x],f[x][1]+max(g[x],f[x][2]));
		}else{
			g[y]=max(f[x][0],g[x])+1;
			if(f[x][1]==f[y][0]+1) dis2[y]=max(dis2[x],f[x][0]+max(g[x],f[x][2]));
			else dis2[y]=max(dis2[x],f[x][0]+max(g[x],f[x][1]));
		}
		if(dis[y]==d[x][0]) dis2[y]=max(dis2[y],d[x][1]);
		else dis2[y]=max(dis2[y],d[x][0]);
		dfs2(y,x);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>k;
		if(n<=10){
			for(int i=0;i<n;i++) G[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				u--;v--;
				G[u].push_back(v);
				G[v].push_back(u);
				e[i]={u,v};
			}
			ans=inf;
			for(int i=0;i<1<<n;i++){
				if(__builtin_popcount(i)!=k) continue;
				for(int j=0;j<n;j++) fa[j]=j;
				for(int j=0;j<n;j++) flag[j]=i>>j&1;
				for(int j=1;j<n;j++){
					if(flag[e[j].u]&&flag[e[j].v]) fa[find(e[j].u)]=find(e[j].v);
				}
				int cnt=0;
				for(int j=0;j<n;j++){
					if(flag[j]&&fa[j]==j) cnt++;
				}
				if(cnt>2) continue;		
				int res=0;
				for(int j=0;j<n;j++) res=max(res,bfs(j));
				ans=min(ans,res);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(k==2){
			for(int i=1;i<=n;i++) G[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				G[u].push_back(v);
				G[v].push_back(u);
			}
			dfs(1,0);
			ans=inf;
			dfs2(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 1
10 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/