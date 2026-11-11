#include<bits/stdc++.h>
#define int long long

using namespace std;

int read(){
	int t=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		t=t*10+ch-48;
		ch=getchar();
	}
	return t*f;
}

void write(int f){
	if(f>9)write(f/10);
	putchar(f%10+'0');
}

int c,n,m,d,q;
int a[500005]; //ok
int fa[501005]; //ok
//warning
struct Edge{
	int u,v,w;
	bool operator<(const Edge &other)const{
		return w<other.w;
	}
};
vector<Edge>e;

int findf(int x){
	return x==fa[x]?x:fa[x]=findf(fa[x]);
}

vector<pair<int,int>>G[501005];
int up[21][501005];
int cost[21][501005];
int dep[501005];
void dfs(int u,int f,int d){
	dep[u]=d;
	up[0][u]=f;
	for(auto v:G[u]){
		if(v.first==f)continue;
		cost[0][v.first]=v.second;
		dfs(v.first,u,d+1);
	}
}

int lca(int u,int v){
	int res=0;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[up[i][u]]>=dep[v]){
			res+=cost[i][u];			
			u=up[i][u];
		}
	}
	if(u==v)return res;
	for(int i=20;i>=0;i--){
		if(up[i][u]!=up[i][v]){
			res+=cost[i][u]+cost[i][v];
			u=up[i][u];
			v=up[i][v];
		}
	}
	res+=cost[0][u]+cost[0][v];
	return res;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	
	for(int i=1;i<=n;i++){
		int tmp=read();
		int tmpa,tmpb;
		for(int j=1;j<=tmp;j++){
			tmpa=read(),tmpb=read();
			e.push_back({tmpa,m+i,tmpb});
		}
	}
	
	sort(e.begin(),e.end());
	
	for(int i=0;i<e.size();i++){
		int fA=findf(e[i].u);
		int fB=findf(e[i].v);
		if(fA==fB)continue;
		fa[fA]=fB;
		G[e[i].u].push_back({e[i].v,e[i].w});
		G[e[i].v].push_back({e[i].u,e[i].w});
	}
	
	dfs(1,1,0);
	
	for(int i=1;i<=20;i++){
		for(int j=1;j<=m+n;j++){
			up[i][j]=up[i-1][up[i-1][j]];
			cost[i][j]=cost[i-1][up[i-1][j]]+cost[i-1][j];
		}
	}
	
	for(int i=1;i<=q;i++){
		int u=read(),v=read();
		write(lca(u,v)+a[u]+a[v]);
		puts("");
	}
	
	
//	
//	for(auto X:e){
//		cout<<X.u<<" "<<X.v<<" "<<X.w<<"\n";
//	}
//	
//	cout<<"\n";
//	
//	for(int i=1;i<=m+n;i++){
//		for(auto X:G[i]){
//			cout<<i<<" "<<X.first<<" "<<X.second<<"\n";
//		}		
//	}
//
//	cout<<up[0][3]<<" "<<cost[0][3];
//	cout<<up[0][7]<<" "<<cost[0][7];
//	cout<<up[0][2]<<" "<<cost[0][2];
//	cout<<up[0][6]<<" "<<cost[0][6];
	return 0;
}
/*

*/