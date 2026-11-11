#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else if(x<10){
		putchar(x^48);
	}
	else{
		print(x/10);
		putchar((x%10)^48);
	}
}
const int N=1e6;
int n,k;
struct Edge{
	int nxt,to;
}e[N<<1];
int cnt,head[N];
void add(int u,int v){
	e[++cnt]={head[u],v};
	head[u]=cnt;
}
int f[N][2];
int deg[N],in[N],dep[N],dis[N],fa[N],lst[N];
bool vis[N];
int find(int u){
	if(fa[u]!=u)fa[u]=find(fa[u]);
	return fa[u];
}
vector<int>G[N];
bool check(int x){
	queue<int>q;
	for(int i=1;i<=n;i++){
		deg[i]=in[i];
		vis[i]=false;
		fa[i]=i;
		dis[i]=0;
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0,v;i<G[u].size();i++){
			v=G[u][i];
//			cout<<u<<"->"<<v<<'\n';
			deg[v]--;
			dis[v]=max(dis[v],dis[u]+1);
			if(!deg[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]<x||dep[i]<x)continue;
		vis[i]=true;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<' ';
		if(vis[i]){
			tot++;
			if(vis[lst[i]]){
				fa[find(i)]=find(lst[i]);
			}
		}
	}
	if(tot>k)return false;
	tot=0;
//	cout<<'\n';
	for(int i=1;i<=n;i++){
		int fi=find(i);
		if(fi==i&&vis[i])tot++;
	}
	return tot<=2;
}
//int f[N],g[N];
void dfs(int u,int fa){
	lst[u]=fa;
	for(int i=head[u],v;i;i=e[i].nxt){
		v=e[i].to;
		if(v==fa)continue;
		G[v].push_back(u);
		dep[v]=dep[u]+1;
		in[u]++;
		dfs(v,u);
	}
}
//void dfs1(int u,int fa){
//	f[u]=0;
//	for(int i=head[u],v;i;i=e[i].nxt){
//		v=e[i].to;
//		if(v==fa)continue;
//		dfs1(v,u);
//		f[u]=max(f[u],f[v]+1);
//	}
//}
//void dfs2(int u,int fa){
//	for(int i=head[u],v;i;i=e[i].nxt){
//		v=e[i].to;
//		if(v==fa)continue;
//		g[v]=max(g[u])
//		dfs2(v,u);
//	}
//	
//}
void run1(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	if(k==n){
		puts("0");
		for(int i=1;i<=n;i++){
	//		cout<<in[i]<<'\n';
			head[i]=0;
			deg[i]=in[i]=dep[i]=0;
		}
		cnt=0;
		return;
	}
	if(k>=n-2){
		print(1);
		puts("");
		for(int i=1;i<=n;i++){
	//		cout<<in[i]<<'\n';
			head[i]=0;
			deg[i]=in[i]=dep[i]=0;
		}
		cnt=0;
		return;
	}
//	puts("dfasdfasdfasdf");
//	dfs1(1,0);
//	g[1]=f[1];
//	dfs2(1,0);
	int rt=3;
//	for(int i=1;i<=n;i++){
//		if(g[rt]>g[i])rt=i;
//	}
	dfs(rt,0);
	int l=0,r=n,ans=n;
	while(l<=r){
//		cout<<l<<' '<<r<<'\n';
//		puts("dfasdfasdfasdf");
//		getchar();
		int mid=l+r>>1;
//		cout<<mid<<' ';
		if(check(mid)){
//			cout<<"T\n";
			ans=mid;
			r=mid-1;
		}
		else{
//			cout<<"F\n";
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
//	puts("asdtasdtsdta");
	for(int i=1;i<=n;i++){
//		cout<<in[i]<<'\n';
		head[i]=0;
		deg[i]=in[i]=dep[i]=0;
	}
	cnt=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c<=40){
		while(T--){
			run1();
		}
	}
//	cout<<ans<<'\n';
}
