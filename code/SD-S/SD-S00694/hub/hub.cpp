#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k,c,T,tot;
int head[N],dis[N];
bool vis[N],vis2[N];
vector<int> vec;
struct E{
	int nxt,to;
}edge[N<<1];
void add(int x,int y){
	edge[++tot]={head[x],y};
	head[x]=tot;
}
void dfs(int x,int fa){
	vis2[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int xx=edge[i].to;
		if(!vis[xx]) continue;
		if(xx==fa) continue;
		dfs(xx,x);
	}
}
void dfs2(int x,int fa){
	if(!vis[x]) dis[x]=dis[fa]+1;
	else dis[x]=0;
	for(int i=head[x];i;i=edge[i].nxt){
		int xx=edge[i].to;
		if(xx==fa) continue;
		dfs2(xx,x);
	}
}
void solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	int ans=n;
	for(int msk=0;msk<(1<<n);msk++){
		if(__builtin_popcount(msk)!=k) continue; 
		for(int i=1;i<=n;i++) vis[i]=vis2[i]=0,dis[i]=n;
		for(int i=1;i<=n;i++){
			if((msk>>(i-1))&1) vis[i]=1;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if(!vis2[i]&&vis[i]){
				dfs(i,0);
				res++;
				vec.push_back(i);
			}
		if(res>2) continue;
		int mx=0;
		for(int i:vec){
			dfs2(i,0);
			for(int j=1;j<=n;j++) mx=max(mx,dis[j]);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>T;
	while(T--) solve();
	return 0;
} 
