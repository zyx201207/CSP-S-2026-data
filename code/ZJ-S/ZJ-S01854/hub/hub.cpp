#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }
const int M=2e6+5;
int n,k,c;
struct Edge{
	int to,i,nxt;
}e[M*2];
int hd[M],tot,S,T;
void add(int u,int v,int i){
	e[++tot].to=v;
	e[tot].i=i;
	e[tot].nxt=hd[u];
	hd[u]=tot;
}
int u[M],v[M],deg[M],dia;
vector<int>cut_edge;

int dep[M],mx[M],son[M];

void getdep(int x,int fa){
	if(!fa)dep[x]=fa;
	for(int i=hd[x];i;i=e[i].nxt)if(e[i].to!=fa){
		int y=e[i].to;
		dep[y]=dep[x]+1;		
		getdep(y,x);
	}
}
int dfn[M],tim,out[M];
void dfs(int x,int j){
	dfn[x]=++tim;
	mx[x]=0;
	for(int i=hd[x];i;i=e[i].nxt)if(e[i].i!=j){
		int y=e[i].to;
		dfs(y,e[i].i);
		chkmax(mx[x],mx[y]+1);
	}
	out[x]=tim;
	// cout<<"s="<<j<<" mx="<<mx[x]<<endl;
	if(dfn[x]<=dfn[T]&&dfn[T]<=tim){
		if(dia&1){
			if(mx[x]==dia/2)cut_edge.pb(j);
		}else{
			if(mx[x]==dia/2||mx[x]==dia/2-1)cut_edge.pb(j);
		}
	}
}
bool vis[M];
void procedure(){
	n=read(),k=read();
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		add(u[i],v[i],i);
		add(v[i],u[i],i);
	}
	getdep(1,0);
	S=T=1;
	for(int i=2;i<=n;i++) if(dep[i]>dep[S])S=i;
	getdep(S,0);
	for(int i=2;i<=n;i++) if(dep[i]>dep[T])T=i;
	dia=dep[T];

	tim=0;
	dfs(S,0);
	// cout<<"dia="<<dia<<endl;
	// cout<<"find cut_edge="<<cut_edge<<endl;
	
	int ans=n;
	int count=0;

	if(c<=10) {
		cut_edge.clear();
		for(int i=0;i<n;i++)cut_edge.pb(i);
	}else{
		// for(int x: cut_edge) vis[x]=1;
		// for(int i=0;i<n;i++) if(!vis[i])cut_edge.pb(i);
	}
	
	// for(int s=0;s<n;s++){
	for(int s:cut_edge){
		// cout<<"here s="<<s<<" u="<<u[s]<<" v="<<v[s]<<endl;
		++count;
		int res=n;
		for(int j=1;j<=n;j++)deg[j]=0;
		for(int j=1;j<n;j++)if(s!=j)
			deg[u[j]]++,deg[v[j]]++;
		vector<int>q;
		for(int j=1;j<=n;j++)if(deg[j]==1)q.pb(j);

		// cerr<<"delete edge "<<s<<endl;

		int now=0,flg=1;
		while(res>k){
			now++;
			// assert(q.size());
			if(!q.size()){
				flg=0;
				break;
			}
			vector<int>q2;
			for(int x: q){
				if(!deg[x])continue;
				res--;
				for(int i=hd[x];i;i=e[i].nxt){
					int y=e[i].to;
					if(e[i].i==s||!deg[e[i].to]) continue;
					deg[x]--,deg[y]--;
					if(deg[y]==1)q2.pb(y);
				}
			}
			swap(q,q2);
		}
		if(flg)chkmin(ans,now);
		// if(c>10 && (++count)*n>2e7) break;
	}
	printf("%d\n",ans);
}
void clear(){
	for(int i=1;i<=n;i++)hd[i]=deg[i]=0; tot=0;
}
int main(){
	assert(freopen("hub.in","r",stdin));
	assert(freopen("hub.out","w",stdout));
	c=read(); int T=read();
	while(T--){
		// cout<<"cut test"<<endl;
		procedure(),clear();
	}
}