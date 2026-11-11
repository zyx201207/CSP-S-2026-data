#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=1e6+5;
int c,t,n,k;
struct EdGe{
	int frt[N],to[N<<1],nxt[N<<1],top;
	void add(int u,int v){
		nxt[++top]=frt[u];
		frt[u]=top;
		to[top]=v;
	}
	void double_add(int u,int v){
		add(v,u);
		add(u,v);
	}
	void init(){
		top=0;
		FOR(i,1,n) frt[i]=0;
	}
}e;
int bj[N];
int ans;
int vis[N];
void col(int u,int fa){
	vis[u]=1;
	for(int i=e.frt[u];i;i=e.nxt[i]){
		int v=e.to[i];
		if(v==fa) continue;
		if(bj[v]&&!vis[v]) col(v,u);
	}
}
int dis[N];
void cla(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int i=e.frt[u];i;i=e.nxt[i]){
		int v=e.to[i];
		if(v==fa) continue;
		cla(v,u);
	}
}
void pan(){
	int ct=0;
	FOR(i,1,n){
		if(bj[i]) ++ct;
		vis[i]=0;
		dis[i]=n;
	}
	if(ct!=k) return ;
	ct=0;
	FOR(i,1,n){
		if(bj[i]&&!vis[i]){
			col(i,i);
			++ct;
		}
	}
	if(ct>2) return ;
	FOR(i,1,n){
		if(bj[i]){
			dis[i]=0;
			cla(i,i);
		}
	}
	int an=0;
	FOR(i,1,n) an=max(an,dis[i]);
	ans=min(ans,an);
}
void dfs(int x){
	if(x>n){
		pan();
		return ;
	}
	bj[x]=1;
	dfs(x+1);
	bj[x]=0;
	dfs(x+1);
}
void bl(){
	ans=n;
	dfs(1);
	printf("%d\n",ans);
}
void mb(){
	ans=n;
	FOR(i,1,n){
		FOR(j,i+1,n){
			FOR(k,1,n) dis[k]=n;
			dis[i]=dis[j]=0;
			cla(i,i);
			cla(j,j);
			int an=0;
			FOR(i,1,n) an=max(an,dis[i]);
			ans=min(ans,an);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=iread();
	t=iread();
	while(t--){
		n=iread();
		k=iread();
		e.init();
		rop(i,1,n){
			e.double_add(iread(),iread());
		}
		if(k==2) mb();
		else bl();
	}
	return 0;
}

