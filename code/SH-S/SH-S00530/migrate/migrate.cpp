#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300,M=2e6+10;
int n,m,pos[M];
bool graph[N][N];
int dist[N];
bool vis[N];
int cnt[N];
void f(int u){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[u]=0;
	for(int t=1;t<n;t++){
		u=0;
		for(int v=1;v<=n;v++)if(!vis[v]&&dist[v]<dist[u])u=v;
		vis[u]=1;
		for(int v=1;v<=n;v++)if(graph[u][v])dist[v]=min(dist[v],dist[u]+1);
	}
}
struct node{
	int v,w;
};
int bfs(int u){
	memset(cnt,0,sizeof(cnt));
	queue<node>q;
	q.push({u,0});
	int res=0;
	while(q.size()){
		node f=q.front();
		q.pop();
		u=f.v;
		int w=f.w;
		if(w>dist[u])continue;
		else if(w==dist[u])cnt[u]++;
		for(int v=1;v<=n;v++){
			if(graph[u][v]){
				q.push({v,w+1});
			}
		}
	}
	for(u=0;u<=n;u++)if(cnt[u]==2)res++;
	return res;
}
void solve1(){
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>pos[i];
		for(int j=1;j<i;j++){//½¨Í¼
			if(pos[i]-pos[j]<=m)graph[j][i]=1; 
			else graph[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		f(i);
		ans+=bfs(i);
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>pos[i];
	int d=pos[2]-pos[1];
	d=m/d;
	if(d<2)cout<<"0\n";
	else cout<<max(0ll,n-2*d+1)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,_;
	cin>>c>>_;
	if(c<7)while(_--)solve1();
	else if(c==11||c==12)while(_--)solve2();
	return 0;
} 
