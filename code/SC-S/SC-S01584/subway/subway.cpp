#include<bits/stdc++.h>
//#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f*x;
}
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M],dis[N+M],vis[N+M];
vector<pair<int,int>>edge[N+M];
//edge[1~m]站台,edge[m+1~m+n]线路
void dijkstra(int u){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,
	vector<pair<int,int>>,
	greater<pair<int,int>>>q;
	q.push({0,u});dis[u]=0;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=true;
		for(auto i:edge[x]){
			int to=i.first;
			int w=i.second;
			if(dis[to]>dis[x]+w){
				dis[to]=dis[x]+w;
				q.push({dis[to],to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	c=read();n=read();
	m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			edge[a].emplace_back(make_pair(m+i,t));
			edge[m+i].emplace_back(make_pair(a,t));
		}
	}
	for(int i=1;i<=q;i++){
		int u=read(),v=read();dijkstra(u);
		cout<<dis[v]+w[u]+w[v]<<'\n';
	}
	return 0;
}