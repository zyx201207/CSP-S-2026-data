#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9;
int C,T,n,K,ans;
int h[N],tot;
int g[N][N];
struct Node{
	int to,nxt;
}e[2*N];
void Add(int u,int v){
	tot++;
	e[tot].to=v,e[tot].nxt=h[u];
	h[u]=tot;
}
int fa[N];
bool fvis[N];
int Find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
int idx=0;
void check(int S){
	idx++;
//	cout<<idx<<'\n';
	for(int i=1;i<=n;i++) fa[i]=i,fvis[i]=0;
	for(int u=1;u<=n;u++){
		if((S>>(u-1))&1){
//			cout<<u<<' ';
			for(int i=h[u];i;i=e[i].nxt){
				int v=e[i].to;
				if((S>>(v-1))&1){
					int fu=Find(u),fv=Find(v);
					fa[fu]=fv;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int fu=Find(i);
		if(!((S>>(i-1))&1)) continue;
		if(!fvis[fu]) fvis[fu]=1,cnt++;
	}
//	cout<<cnt<<'\n';
	if(cnt>2) return ;
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=INF;
		for(int j=1;j<=n;j++){
			if((S>>(j-1))&1) mn=min(mn,g[i][j]);
		}
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
}
void dfs(int cur,int k,int S){
	if(cur==n){
		if(k!=K) return ;
		check(S);
		return ;
	}
	if(k<K) dfs(cur+1,k+1,S|(1<<cur));
	dfs(cur+1,k,S);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>K;
		ans=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]=INF;
		}
		for(int i=1;i<=n;i++) h[i]=0,g[i][i]=0;
		tot=0;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			Add(u,v),Add(v,u);
			g[u][v]=g[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
		dfs(0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
//Escape.
