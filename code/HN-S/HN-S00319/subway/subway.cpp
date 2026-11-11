#include<bits/stdc++.h>
using namespace std;
const int maxn=500500*40+5;
int c,n,m,d,Q;//没用,枢纽数量,站点数量,没用,测试组数 
int ml[500005];//e 
int k,l,kl;//没用 
int x,y;
bool vis[500005];
int dis[500005];
int z[maxn],v[maxn],h[maxn],q[maxn],sul;
//中点，路程，头头，起点； 
int dfs(int x){
	for(int i=q[x];i!=0;i=h[i]){ 
		if(vis[z[i]]) continue; 
		int xi=z[i];
//		cout<<"经过"<<x<<"到达"<<xi<<"有这条"<<i<<"路，原本要走"<<dis[xi]<<"，但还有一条是"<<dis[x]+v[i]<<"\n" ;
		dis[xi]=min(dis[xi],dis[x]+v[i]);
		
		vis[x]=true;dfs(xi);vis[x]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>ml[i];
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&kl);
		for(int j=1;j<=kl;j++){//k点到A点滴距离l
			cin>>k>>l; 
			z[++sul]=i+m,v[sul]=l,h[sul]=q[i],q[i]=sul;
			z[++sul]=k,v[sul]=l,h[sul]=q[i+m],q[i+m]=sul;
		}
	}
//	for(int i=1;i<=sul;i++){
//		cout<<"第"<<i<<"条路到达"<<z[i]<<"走了"<<v[i]<<"\n";
//	}

	while(Q--){
		cin>>x>>y;
		for(int i=1;i<=sul;i++) dis[i]=0x7f7f7f7f,vis[i]=false;
		dis[x]=0;
		dfs(x);
		cout<<dis[y]+ml[x]+ml[y]<<"\n";
	}
	return 0;
} 
