#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }
const int M=2e6+5;
int n,k;
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
int u[M],v[M],deg[M],dia,cut_edge;

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
	if(dfn[x]<=dfn[T]&&dfn[T]<=tim&&mx[x]==dia/2)
		cut_edge=j;
}
void procedure(){
	n=read(),k=read();
	for(int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		add(u[i],v[i],i);
		add(v[i],u[i],i);
		// cout<<"here "<<u[i]<<" "<<v[i]<<" "<<i<<endl;
	}
	getdep(1,0);
	S=T=1;
	for(int i=2;i<=n;i++) if(dep[i]>dep[S])S=i;
	getdep(S,0);
	for(int i=2;i<=n;i++) if(dep[i]>dep[T])T=i;
	dia=dep[T];

	tim=0;
	dfs(S,0);

	// cout<<"find cut_edge="<<cut_edge<<endl;
	
	int ans=n;
	for(int s=0;s<n;s++){
	// for(int s:{cut_edge}){
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
			// cout<<"Turn "<<now<<endl;
			// for(int x: q) cout<<x<<" "; cout<<endl;
			assert(q.size());
			// if(!q.size()){
			// 	flg=0;
			// 	break;
			// }
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
		chkmin(ans,now);
		if(now==6){
			cout<<"here s="<<s<<" cut "<<u[s]<<" "<<v[s]<<endl;
		}
	}
	printf("%d\n",ans);
}
void clear(){
	for(int i=1;i<=n;i++)hd[i]=deg[i]=0; tot=0;
}
int main(){
	assert(freopen("hub.in","r",stdin));
	assert(freopen("hub.ans","w",stdout));
	int c=read(),T=read();
	while(T--){
		cout<<"start"<<endl;
		procedure(),clear();
	}
}