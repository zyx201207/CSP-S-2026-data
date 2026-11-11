#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int mx=1e5+10,mxn=5e5+10;
const ll inf=9223372036854775807;
int c,n,m,d,q;
int w[mxn],a[mx][mxn],t[mx][mxn],x[mx],y[mx];
int head[mxn],cnt;
ll ans;
struct edge{
	int v,next;
	int name;
}eg[mxn];
void addedge(int u,int v,int name){
	eg[++cnt].v=v;
	eg[cnt].next=head[u];
	head[u]=cnt;
	eg[cnt].name=name;
}
void dfs(int u,int nf,ll we,int fa,int name){
	if(u==nf){
		ans=min(ans,we+t[name][u]);
	}
	for(int i=head[u];i;i=eg[i].next){
		int v=eg[i].v;
		if(v==fa)continue;
		if(name==0){
			dfs(v,nf,we+t[eg[i].name][u],u,eg[i].name);
		}
		if(eg[i].name!=name){
			dfs(v,nf,we+t[name][v]+t[eg[i].name][v],u,eg[i].name);
		}else{
			dfs(v,nf,we,u,name);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k1;
		scanf("%d",&k1);
		for(int j=1;j<=k1;j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j!=1){
				addedge(a[i][j-1],a[i][j],i);
				addedge(a[i][j],a[i][j-1],i);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++){
		ans=inf;
		dfs(x[i],y[i],0,0,0);
		ans+=(w[x[i]]+w[y[i]]);
		printf("%lld ",ans);
	}
	printf("/n");
	return 0;
}