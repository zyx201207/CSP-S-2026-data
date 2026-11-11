#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=1e3+10;
const int mod=1e9+7;
const int inf=1e17;
inline int mm(int X,int MOD=mod){
	return (X%MOD+MOD)%MOD;
}
namespace sub1{
	int n,m;
	vector<int> g[N];
	bool vis[N];
	int dis[N];
	void dfs(int u,int fa){
		if(u==0){
			return ;
		}
		if(vis[u]){
			dis[u]=0;
		}else{
			dis[u]=min(dis[u],dis[fa]+1);
		}
		for(int v:g[u]){
			if(v==fa){
				continue;
			}
			dfs(v,u);
		}
	}
	int pos1,pos2;
	int ans;
	void init(int u,int fa,int cnt,int d){
		if(cnt<0){
			return ;
		}
		if(d==0){
			for(int i=1;i<=n;i++){
				dis[i]=inf;
			}
			dfs(pos1,0);
			dfs(pos2,0);
			int mx=0;
			for(int i=1;i<=n;i++){
				mx=max(dis[i],mx);
			}
			ans=min(mx,ans);
			return ;
		}
		for(int v:g[u]){
			if(v==fa){
				continue;
			}
			vis[v]=0;
			init(v,u,cnt,d);
			if(vis[u]){
				vis[v]=1;
				init(v,u,cnt,d-1);
				vis[v]=0;
			}else{
				vis[v]=1;
				if(pos1){
					pos2=v;
					init(v,u,cnt-1,d-1);
					vis[v]=0;
					pos2=0;
				}else{
					pos1=v;
					init(v,u,cnt-1,d-1);
					vis[v]=0;
					pos1=0;
				}
			}
		}
	}
	void solve(){
		for(int i=1;i<=n;i++){
			g[i].clear();
		} 
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=inf;
		init(1,0,2,m);
		vis[1]=1;
		pos1=1;
		init(1,0,1,m-1);
		vis[1]=0;
		pos1=0;
		vis[1]=1;
		pos1=1;
		init(1,0,0,m-1);
		vis[1]=0;
		pos1=0;
		cout<<ans<<endl;
		return ;
	}
	int main(){
		int T;
		cin>>T;
		while(T--){
			solve();
		}
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int Case;
	cin>>Case;
	if(Case<=3){
		sub1::main();
		return 0;
	}
	return 0;
}

