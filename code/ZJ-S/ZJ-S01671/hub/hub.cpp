#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int c,t,n,k;
ll ans; 
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int son[maxn*2],nxt[maxn*2],lnk[maxn],cnt;
void add_e(int x,int y){
	son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}
vector<int> p;
bool vis[maxn];
void dfs1(int u,int pre){
	vis[u]=0;
	for(int j=lnk[u];j;j=nxt[j]){
		int v=son[j];
		if(v==pre||!vis[v])continue;
		dfs1(v,u);
	}
}
int f[maxn][21],dep[maxn];
void dfs2(int u,int pre){
	f[u][0]=pre;dep[u]=dep[pre]+1;
	for(int j=lnk[u];j;j=nxt[j]){
		int v=son[j];
		if(v==pre)continue;
		dfs2(v,u);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(dep[f[a][i]]>=dep[b])a=f[a][i];
	}
	if(a==b)return a;
	for(int i=20;i>=0;i--){
		if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
	}
	return f[a][0];
}
void clear(){
	for(int i=1;i<=n;i++){
		lnk[i]=0;
		for(int j=0;j<=20;j++)f[i][j]=0;
	}
	cnt=0;ans=1<<30;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();
		clear();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			add_e(x,y);add_e(y,x);
		}
		dfs2(1,0);
		for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k)continue;
			p.clear();
			for(int j=1;j<=n;j++){
				vis[j]=0;
				if(i&(1<<(j-1)))p.push_back(j),vis[j]=1;
			}
			int num=0;
			for(int j=1;j<=n;j++){
				if(vis[j])dfs1(j,0),num++;
			}
			if(num>2)continue;
//			cout<<i<<endl;
//			for(int u:p)cout<<u<<" ";cout<<endl;
			ll cur=0;
			for(int j=1;j<=n;j++){
				ll now=1<<30;
				for(int u:p){
					now=min(now,(ll)dep[j]+dep[u]-dep[lca(j,u)]*2);
				}
				cur=max(cur,now);
//				cout<<now<<" ";
			}
//			cout<<endl;
			ans=min(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
