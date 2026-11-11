#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct node{
	int u,v,nxt;
}e[N<<1];
int head[N],cnt,n,k;
void add(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int col[N],vis[N],ans=0x3f3f3f3f;
void dfs1(int now,int fa){
	if(!col[now])return;vis[now]=1;
	for(int i=head[now],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa)continue;
		dfs1(v,now);
	}
}
int dfs2(int now,int fa,int dep){
	if(col[now])return dep;
	int mn=0x3f3f3f3f;
	for(int i=head[now],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa)continue;
		mn=min(mn,dfs2(v,now,dep+1));
	}
	return mn;
}
void dfs(int now){
	if(now==n+1){
		int tot=0;
		for(int i=1;i<=n;i++){
			tot+=col[i];
			vis[i]=0;
		}
		if(tot!=k)return;
		tot=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&col[i]){
				tot++;dfs1(i,0);
			}
		}
		if(tot>2)return;
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,dfs2(i,0,0));
		}
		ans=min(ans,mx);
		return;
	}
	col[now]=0;dfs(now+1);
	col[now]=1;dfs(now+1);
}
void solve(){
	ans=0x3f3f3f3f;
	memset(head,0,sizeof head);
	for(int i=1;i<=cnt;i++){
		e[i].u=0;e[i].v=0;e[i].nxt=0;
	}
	cnt=0;
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs(1);cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T,cas;cin>>cas;cin>>T;
	while(T--)solve();

	return 0;
}

