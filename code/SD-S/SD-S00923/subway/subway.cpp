#include<bits/stdc++.h>
#define PII pair<int,int> 
using namespace std;
const int N=1e6+10;
priority_queue <PII,vector<PII>,greater<PII> > q;
int e[N],ne[N],w[N],h[N];
long long dis[N],vis[N],idx,s;
void add(int a,int b,int c){
	e[idx]=b;ne[idx]=h[a];w[idx]=c;h[a]=idx++;
}
long long n,m;
void dijkstra(){
	fill(dis,dis+1+m+n,0x3f3f3f3f);
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];~i;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				q.push({dis[v],v});
			}
		}
	}
}
int ww[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int d,c,q;
	cin>>c>>n>>m>>d>>q;
	fill(h,h+m+n+10,-1);
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	for(int i=1;i<=q;i++){
		int uwu;
		cin>>s>>uwu;
		fill(vis+1,vis+n+m+10,0);
		dijkstra();
		cout<<ww[s]+dis[uwu]+ww[uwu]<<'\n';
	}
	return 0;
}
