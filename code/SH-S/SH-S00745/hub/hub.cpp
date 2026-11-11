#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int C,n,k,dis[1005][1005],vis[1005],d[1005],f,ans;
vector<int> vec[N];
void dfs(int rt,int u,int fa){
	if(u!=rt)dis[rt][u]=dis[rt][fa]+1;
	for(int v:vec[u]){
		if(v==fa)continue;
		dfs(rt,v,u);
	}
}
void dfs2(int rt,int u,int fa){
	for(int v:vec[u]){
		if(v==fa)continue;
		if(vis[v]&&dis[rt][v]==ans){
			f=u;
			return;
		}
		dfs2(rt,v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)vec[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	if(C==13||C==14){
		int x=n/2+3;
		cout<<max((x-k)/4+1,1ll)<<'\n';
		return;
	}
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++)dfs(i,i,0);
	int res=1e18;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(vis,0,sizeof(vis));
			memset(d,0,sizeof(d));
			vis[i]=vis[j]=1;
			int mx=0;ans=0;
			for(int u=1;u<=n;u++){
				d[u]=min(dis[u][i],dis[u][j]);
				if(d[u]>ans){
					ans=d[u];
					mx=u;
				}
			}
			for(int p=1;p<=k-2;p++){
				dfs2(mx,mx,0);
				vis[f]=1;
				for(int u=1;u<=n;u++){
					d[u]=min(d[u],dis[u][f]);
					if(d[u]>ans){
						ans=d[u];
						mx=u;
					}
				}
			}
			res=min(res,ans);
		}
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
