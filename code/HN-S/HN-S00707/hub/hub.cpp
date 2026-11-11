#include<bits/stdc++.h>
using namespace std;
const int N=21;
int c,t,n,d,cnt;
int nxt[N],to[N],fa[N];
int op[N],head[N];
int f[N][11],dep[N];
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int u,int pre){
	f[u][0]=pre;
	dep[u]=dep[pre]+1;
	for(int k=1;k<=10;k++)
	f[u][k]=f[f[u][k-1]][k-1];
	for(int e=head[u];e;e=nxt[e]){
		int v=to[e];
		if(v==pre)continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int k=10;k>=0;k--)
	if(dep[f[x][k]]>=dep[y])
	x=f[x][k];
	if(x==y)return x;
	for(int k=10;k>=0;k--)
	if(f[x][k]!=f[y][k]){
		x=f[x][k];
		y=f[y][k];
	}
	return f[x][0];
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
} 
int check(){
	int sum=0;
	for(int i=1;i<=n;i++)
	sum+=op[i];
	if(sum!=d)return n+1;
	int tot=0;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int u=1;u<=n;u++)
	for(int e=head[u];e;e=nxt[e])
	if(op[u]&&op[to[e]])fa[find(u)]=find(to[e]);
	for(int i=1;i<=n;i++)
	if(op[i]&&find(i)==i)tot++;
	if(tot!=2)return n+1;
	int ans=0;
	for(int i=1;i<=n;i++)
	if(!op[i]){
		int mi=n+1;
		for(int j=1;j<=n;j++)
		if(op[j])
		mi=min(mi,dep[i]+dep[j]-2*dep[lca(i,j)]);
		ans=max(ans,mi);
	}
	return ans;
}
int findans(int x){
	if(x>n)return check();
	op[x]=0;
	int ans=findans(x+1);
	op[x]=1;
	return min(ans,findans(x+1));
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			add(u,v);add(v,u);
		}
		dfs(1,0);
		cout<<findans(1)<<endl;
		cnt=0;
		for(int i=1;i<=n;i++)
		head[i]=0;
	}
	return 0;
}
