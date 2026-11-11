#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define r read()
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=1e6+5;
int C,t,n,h[N],tot,ans,col[12],d[12],k;
int dep1[N],dep2[N],z1,z2,fa[N][18],dep[N];
bool c[N];
struct edge{
	int to,nxt;
}e[N<<1];
void Add(int u,int v){
	e[++tot]={v,h[u]};
	h[u]=tot;
}
void dfs1_dfs(int u){
	col[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if((!c[v])||col[v])continue;
		dfs1_dfs(v);
	}
}
bool check(){
	memset(col,0,sizeof(col));
	int tmp=0,cnt=0;
	for(int i=1;i<=n;i++)tmp+=c[i];
	if(tmp!=k)return false;
	for(int i=1;i<=n;i++){
		if((!col[i])&&c[i]){
			dfs1_dfs(i);
			++cnt;
		}
		if(cnt>2)return false;
	}
	return true;
}
int calc_dfs(int u,int fa){
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)continue;
		if(c[u])return 0;
		d[u]=min(d[u],calc_dfs(v,u)+1);
	}
	return d[u];
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++){
		memset(d,0x3f,sizeof(d));
		res=max(res,calc_dfs(i,0));
	}
	return res;
}
void dfs1(int x){
	if(x==n+1){
		if(!check())return;
		ans=min(ans,calc());
		return ;
	}
	c[x]=0;
	dfs1(x+1);
	c[x]=1;
	dfs1(x+1);
}
void dfs(int u,int fat){
	dep[u]=dep[fat]+1,fa[u][0]=fat;
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fat)continue;
		dfs(v,u);
		if(dep[v]>dep[z1])z1=v;
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int w1(int u,int v){
	int lca=LCA(u,v);
	return dep[u]+dep[v]-2*dep[lca];
}
int CALC(int u,int v){
	int res=0;
	res=max(w1(u,z1),w1(v,z1));
	res=max(res,w1(u,z2));
	res=max(res,w1(v,z2));
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=r,t=r;
	while(t--){
		n=r,tot=0,ans=INT_MAX,k=r;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1;i<n;i++){
			int u=r,v=r;
			Add(u,v);
			Add(v,u);
		}
		if(C<=3){
			dfs1(1);
			printf("%d\n",ans);
		}
		else if(C==7||C==11||C==12){
			dfs(1,0);
			z2=z1;
			for(int i=1;i<=n;i++)dep[i]=0;
			z1=0;
			dfs(z2,0);//z1,z2 zhijing
			for(int j=1;j<=17;j++){
				for(int i=1;i<=n;i++){
					fa[i][j]=fa[fa[i][j-1]][j-1];
				}
			}
//			for(int i=1;i<=n;i++){
//				if(!(i%1000))cerr<<i<<endl;
//				for(int j=i+1;j<=n;j++){
//					ans=min(ans,CALC(i,j));
//				}
//			}
//			cerr<<dep[z1]/4<<endl;
			printf("%d\n",dep[z1]/4);
		}
		else printf("%d\n",n/4);
	}
	return 0;
}

