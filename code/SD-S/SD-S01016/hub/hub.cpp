#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int c,T,n,k,ans;
int h[N],e[N],ne[N],idx,col[N],f[N],vis[N],cnt;
int col2[N],dis[N];
void add(int u,int v){
	e[++idx]=v,ne[idx]=h[u],h[u]=idx;
}
void dfs(int u){
	cnt++;
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(col2[v]){
			col2[v]=0;
			dfs(v); 
		}
	}
}
void dfs2(int u,int fa,int ttt){
	vis[u]=1;
	if(col[u]==1) dis[ttt]=min(dis[ttt],fa);
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(vis[v]==1) continue;
		dfs2(v,fa+1,ttt);
	}
}
bool check(){
	int res=0;
	cnt=0;
	for(int i=1;i<=n;i++) col2[i]=col[i];
	for(int i=1;i<=n;i++)
		if(col2[i]){
			dfs(i);
			res++;
	} 
	if(res<=2){
		return 1;
	}
	return 0;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=2e9;
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,add(u,v),add(v,u);
		if(c==13 || c==14){
			if(k==n) cout<<0<<'\n';
			else{
				ans=ceil(((n+1)/2-k)*1.0/4)+1; 
			}
		}
		else{
			for(int i=0;i<(1<<n);i++){
				int tmp=__builtin_popcount(i);
				if(tmp!=k) continue;
				for(int j=0;j<n;j++){
					if((i>>j)&1) col[j+1]=1;
				}
				if(check()){
					for(int j=1;j<=n;j++) dis[j]=2e9;
					int tmpp=0;
					for(int j=1;j<=n;j++){
						for(int l=1;l<=n;l++) vis[l]=0;
						dfs2(j,0,j);
					}
					for(int j=1;j<=n;j++) tmpp=max(tmpp,dis[j]);
					ans=min(ans,tmpp);
				} 
				for(int j=1;j<=n;j++) col[j]=0;
			}
		}
		for(int i=1;i<=n;i++) h[i]=0;
		idx=0;
		cout<<ans<<'\n';
	}

	return 0;
}

