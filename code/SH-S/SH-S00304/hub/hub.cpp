#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int maxn=5e5+10;
int c,T,n,k,a[maxn];
vector<int>g[maxn];
int cnt;
bool vis[maxn];
int dis[maxn],r,ans,num;
void dfs(int u,int fa){
	//cout<<"dfs"<<'\n';
	if(vis[u]==1&&vis[fa]==0)cnt++;
	for(auto v : g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void dfss(int u,int fa,int st){
	//cout<<"dfss"<<'\n';
	if(!vis[u])dis[u]=min(dis[u],dis[fa]+1);
	for(auto v : g[u]){
		if(v==fa)continue;
		dfss(v,u,st);
	}
	if(st==2)r=max(r,dis[u]);
}
void df(int i){
	//cout<<i<<'\n';
	if(i==n+1&&num==k){
		r=0;
		cnt=1;
		dfs(a[1],a[1]);
		if(cnt>2)return;
		for(int i=1;i<=n;i++)dis[i]=n;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				dis[i]=0;
				dfss(i,i,1);
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				dfss(i,i,2);
				break;
			}
		}
		ans=min(ans,r);
		return;
	}
	else if(i==n+1)return;
	if(num<k){
		a[++num]=i;
		vis[i]=1;
		df(i+1);
		vis[i]=0;
		a[num--]=0;
		df(i+1);
	}
	else{
		vis[i]=0;
		df(i+1);
	}
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//cout<<n<<' '<<k<<'\n';
	ans=n;
	num=0;
	df(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub2.in","r",stdin);
	//freopen("hub.out","w",stdout);
	/*
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	*/
	
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
