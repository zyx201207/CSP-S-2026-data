#include<bits/stdc++.h>
using namespace std;
inline long long rd(){long long f=1,x=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline void wt(long long x,int opt){int top=0;char a[105];if(x<0)putchar('-'),x=-x;do{a[++top]=x%10+'0';x/=10;}while(x);for(int i=top;i>=1;i--)putchar(a[i]);if(opt==1)putchar(' ');if(opt==2)putchar('\n');}
int c,n,m,d,q;
int x,y;
long long w[500005];
struct node{
	int u,v;
	int val;
}nd[500005];
int fa[500505];
int tot;
bool cmp(node x,node y){
	return x.val<y.val;
}
int findfa(int u){
	if(fa[u]==u)return u;
	return fa[u]=findfa(fa[u]);
}
bool merge(int x,int y){
	x=findfa(x);y=findfa(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
vector<int>V[500505],E[500505];
long long sum[500505];
int f[500505][25],dep[500505];
int loog[500505];
void dfs(int u,int fa){
	f[u][0]=fa;
	for(int i=1;i<=loog[n+m];i++)f[u][i]=f[f[u][i-1]][i-1];
	dep[u]=dep[fa]+1;
	for(int i=0;i<V[u].size();i++){
		int to=V[u][i],val=E[u][i];
		if(to==fa)continue;
		sum[to]=sum[u]+val;
		dfs(to,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=loog[n+m];i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=loog[n+m];i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n+m;i++)fa[i]=i;
	loog[0]=-1;
	for(int i=1;i<=n+m;i++)loog[i]=loog[i>>1]+1;
	for(int i=1;i<=n;i++){
		int v=i+m;
		int k=rd();
		while(k--){
			tot++;
			nd[tot].u=rd();
			nd[tot].v=v;
			nd[tot].val=rd();
		}
	}
	sort(nd+1,nd+tot+1,cmp);
	for(int i=1;i<=tot;i++)if(merge(nd[i].u,nd[i].v)){
		V[nd[i].u].push_back(nd[i].v);
		V[nd[i].v].push_back(nd[i].u);
		E[nd[i].u].push_back(nd[i].val);
		E[nd[i].v].push_back(nd[i].val);
	}
	dfs(1,0);
	while(q--){
		x=rd();y=rd();
		int l=lca(x,y);
		long long ans=w[x]+w[y];
		ans+=sum[x]+sum[y]-sum[l]-sum[l];
		wt(ans,2);
	}
}

