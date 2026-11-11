#include<bits/stdc++.h>
using namespace std;
const int N=1000200;
int c,t;
int n,k,fa[N][20],dep[N];
vector<int>grp[N];
void dfs(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int v:grp[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(int k=19;k>=0;k--)if(dep[v]-dep[u]>=(1<<k))v=fa[v][k];
	if(u==v)return u;
	for(int k=19;k>=0;k--)if(fa[v][k]!=fa[u][k])v=fa[v][k],u=fa[u][k];
	return fa[v][0];
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
void Main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ans=1e9;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		grp[u].push_back(v);
		grp[v].push_back(u);
	}
	dfs(1,0);
	for(int k=1;k<20;k++)for(int i=1;i<=n;i++)fa[i][k]=fa[fa[i][k-1]][k-1];
	for(int m=0;m<(1<<n);m++){
		if(__builtin_popcount(m)!=k)continue;
		int D=0;
		vector<int>s;
		for(int i=1;i<=n;i++)if(m&(1<<(i-1)))s.push_back(i);
		for(int i=1;i<=n;i++){
			int di=1e9;
			for(int j=0;j<k;j++)di=min(di,dis(i,s[j]));
			D=max(di,D);
		}
		ans=min(ans,D);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		grp[i].clear();
		dep[i]=0;
		for(int j=0;j<20;j++)fa[i][j]=0;
	}
}
int main(){
	scanf("%d%d",&c,&t);
	while(t--)Main();
}
/*
RRRRRRR    PPPPPPP
R      R   P      P     +        +
R      R   P      P     +        +
RRRRRRR    PPPPPPP   +++++++  +++++++
R   R      P            +        +
R    R     P            +        +
R     R    P
R      R   P
*/
