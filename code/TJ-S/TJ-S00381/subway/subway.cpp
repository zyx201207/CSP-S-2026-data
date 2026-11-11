#include<bits/stdc++.h> 
using namespace std;
#define int long long
int c,n,m,d,s,w[500005],k,a,t,head[500005],cnt,f[500005],visit[1010005],x,y;
struct edge{
	int next,to,w;
}e[1010005];
void add(int u,int v,int w){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
}
void dijkstra(int u){
	for(int i=head[u];i!=0;i=e[i].next){
		if(visit[i]){
			continue;
		}
		f[e[i].to]=min(f[e[i].to],f[u]+e[i].w);
		visit[i]++;
		dijkstra(e[i].to);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>s;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=500001;i<=n+500000;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(i,a,t);
			add(a,i,t);
		}
	}
	int nm=n+m+500001;
	while(s--){
		for(int i=1;i<=nm;i++){
			f[i]=LONG_LONG_MAX;
		}
		for(int i=1;i<=nm;i++){
			visit[i]=0;
		}
		cin>>x>>y;
		f[x]=0;
		dijkstra(x);
		for(int i=1;i<=nm;i++){
			visit[i]=0;
		}
		dijkstra(x);
		cout<<f[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
