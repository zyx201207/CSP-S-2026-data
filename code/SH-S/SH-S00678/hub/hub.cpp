#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T=1;
int n,k;
int a[N];//当前集合 
vector<int>g[N];
int ans=1e18;
int dis[N],vis[N];
void bfs(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >q;
	q.push({x,0});
	dis[x]=0;
	while(!q.empty()){
		auto last=q.front();
		q.pop();
		int u=last.first,step=last.second;
		vis[u]=true;
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(!vis[v])q.push({v,dis[v]});
			}
		}
	} 
}
void print(){
	for(int i=1;i<=n;i++){
		if(a[i])cout<<i<<' ';
	}
	cout<<"\n";
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<' ';
	}
	cout<<"\n\n";
}
void h(){
	for(int i=1;i<=n;i++){
		vis[i]=a[i];
	} 
}
bool check(){
	h();
	for(int i=1;i<=n;i++){
		if(vis[i]){
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				auto last=q.front();
				q.pop();
				int u=last;
				for(auto v:g[u]){
					if(vis[v]){
						vis[v]=false;
						q.push(v);
					}
				}
			} 
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				auto last=q.front();
				q.pop();
				int u=last;
				for(auto v:g[u]){
					if(vis[v]){
						vis[v]=false;
						q.push(v);
					}
				}
			} 
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])return true;
	}
	return false;
}
void f(){
	if(check())return ;
	int res=0;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			bfs(i);
//			cout<<i<<'\n';
//			print();
			for(int j=1;j<=n;j++){
				if(a[j])res=max(res,dis[j]);
			}
		}
	} 
//	cout<<ans<<' '<<res<<'\n';
	ans=min(ans,res);
}
void dfs(int i,int cnt){
	if(i>n){
		if(cnt==k)f();
		return ;
	}
	if(cnt<k){
		a[i]=true;
		dfs(i+1,cnt+1);
		a[i]=false;
	}
	dfs(i+1,cnt);
} 
void solve(){
	ans=1e18;
	for(int i=1;i<=n;i++)g[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
//	bfs(1);
//	print();
	dfs(1,0);
	cout<<ans/2<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
