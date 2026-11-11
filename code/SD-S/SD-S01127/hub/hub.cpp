#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n,k,cnt=1,h[1000005],ans=2e18;
struct nd{
	int u,v,nxt;
}e[2000005];
void jb(int u,int v){
	e[++cnt]={u,v,h[u]};
	h[u]=cnt;
}
int xz[1000005],vis[1000005],dis[1000005];
void dfs(int u,int fa,int ds){
	ds++;
	if(ds>1&&xz[u]) return;
	vis[u]=1;
	if(xz[u]) ds=0;
	dis[u]=min(dis[u],ds);
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,ds);
	}
}
void chs(int u,int xc){
	if(xc>k) return;
	if(u==n+1){
//		cout<<"!!!\n";
		if(xc<k) return;
		int cc=0,mxd=0;
		for(int i=1;i<=n;i++) vis[i]=0,dis[i]=2e18;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&xz[i]){
				dfs(i,0,0);
				cc++;
			}
		}
		for(int i=1;i<=n;i++) mxd=max(mxd,dis[i]);
//		cout<<cc<<"\n";
		if(cc<=2){
			ans=min(ans,mxd);
//			for(int i=1;i<=n;i++) cout<<xz[i]<<" ";
//			cout<<"\n";
//			for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//			cout<<"\n";
//			cout<<mxd<<"\n";
		}
		return;
	}
	xz[u]=0;
	chs(u+1,xc);
	xz[u]=1;
	chs(u+1,xc+1);
}
void sol(){
	cnt=1;ans=2e18;
	cin>>n>>k;
	for(int i=1;i<=n;i++) h[i]=0;
	for(int i=1,u,v;i<=n-1;i++){
		cin>>u>>v;
		jb(u,v);jb(v,u);
	}
	chs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>c>>T;
	while(T--) sol();
}

