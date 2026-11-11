#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int cc,t;
int n,k;
int head[N],cnt;
int vis[N],flag[N];
int dep[N];
int p[N][21];
int ans=1e9;
struct node{
	int u,to,next;
}e[N*2];

namespace Flower{
	inline int read(){
		int x=0,f=1;char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	
	inline void write(int x){
		if (x<0) {putchar('-');x=-x;}
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace Flower;

inline void adde(int u,int v){
	e[++cnt].u=u;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	p[u][0]=fa;
	for (int i=1;i<=20;i++)
		p[u][i]=p[p[u][i-1]][i-1];
	for (int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].to;
		if (v==fa)
			continue;
		dfs1(v,u);
	}
}

inline int LCA(int a,int b){
	if (dep[a]>dep[b])
		swap(a,b);
	for (int i=20;i>=0;i--)
		if (dep[a]<=dep[b]-(1<<i))
			b=p[b][i];
	if (a==b)
		return a;
	for (int i=20;i>=0;i--){
		if (p[a][i]==p[b][i])
			continue;
		a=p[a][i];
		b=p[b][i];
	}
	return p[a][0];
}

inline void dfs2(int u,int fa){
	vis[u]=1;
	for (int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].to;
		if (v==fa||!flag[v]||vis[v])
			continue;
		dfs2(v,u);
	}
}

inline bool check(){
	int tot=0;
	for (int i=1;i<=n;i++){
		if (flag[i]&&!vis[i])
			dfs2(i,0),tot++;
	}
//	cout <<"check_tot:: "<<tot<<endl;
	return tot<=2;
}

inline void dfs3(int now,int tot){
	if (tot==k){
		memset(vis,0,sizeof vis);
//		cout <<"check:: "<<endl;
//		for (int i=1;i<=n;i++)
//			if (flag[i])
//				cout <<i<<" ";
//		cout <<endl;
		if (!check())
			return;
		int maxx=0;
		for (int i=1;i<=n;i++){
			if (flag[i])
				continue;
			int minn=1e9;
			for (int j=1;j<=n;j++){
				if (i==j||!flag[j])
					continue;
				int lca=LCA(i,j);
				int dis=dep[i]+dep[j]-2*dep[lca];
//				cout <<"check_dis:: "<<dis<<endl;
				minn=min(minn,dis);
			}
//			cout <<"check_min:: "<<minn<<endl;
			maxx=max(maxx,minn);
		}
//		cout <<"check_max:: "<<maxx<<endl;
		ans=min(ans,maxx);
		return ;
	}
	for (int i=now;i<=n;i++){
		flag[i]=1;
		dfs3(i+1,tot+1);
		flag[i]=0;
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cc=read(),t=read();
	while (t--){
		memset(head,-1,sizeof head);
		memset(flag,0,sizeof flag);
		memset(dep,0,sizeof dep);
		memset(p,0,sizeof p);
		ans=1e9;
		n=read(),k=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			adde(x,y);
			adde(y,x);
		}
		dfs1(1,0);
		dfs3(1,0);
		write(ans),puts("");
	}
	return 0;
}