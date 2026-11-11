#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,m,head[N],vnt,ans,a[N];
bool vis[N];
struct Edge{
	int to,nxt;
}G[N<<1];
void addedge(int u,int v){
	G[++vnt]={v,head[u]};
	head[u]=vnt;
}
int check(){
	int res=0;
	for(int i=1;i<=n;i++){
		a[i]=0x3f3f3f3f;
	}
	for(int j=1;j<=n;j++){
		for(int u=1;u<=n;u++){
			if(vis[u])a[u]=0;
			else{
				for(int i=head[u];i;i=G[i].nxt){
					int v=G[i].to;
					a[u]=min(a[u],a[v]+1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		res=max(res,a[i]);
	}return res;
}
void dfs(int x,int lim){
	if(x>lim){
		ans=min(ans,check());
		return ;
	}
	for(int u=1;u<=n;u++){
		if(vis[u])continue ;
		int flag=0;
		for(int l=head[u];l;l=G[l].nxt){
			int v=G[l].to;
			flag|=vis[u];
		}
		if(!flag)continue ;
		vis[u]=1;
		dfs(x+1,lim);
		vis[u]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		ans=n;vnt=0;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			addedge(u,v);
			addedge(v,u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[i]=vis[j]=1;
				dfs(1,m-2);
				vis[i]=vis[j]=0;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
