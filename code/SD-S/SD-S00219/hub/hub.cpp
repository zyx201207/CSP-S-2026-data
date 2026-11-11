#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
} 
int t,n,k,ans;
vector<int>g[N];
vector<int>dot;
int vis[N],viss[N];
void bfs(int s){
	queue<int>q;
	q.push(s);vis[s]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			bool in=0;
			for(auto d:dot)
				if(v==d)in=1;
			if(!in)continue;
			if(vis[v])continue;
			vis[v]=1;q.push(v);
		}
	}
}
int bfs1(int s){
	queue<int>q;
	q.push(s);viss[s]=1;
	int res=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			bool in=0;
			for(auto d:dot)
				if(v==d)in=1;
			if(in)return res;
			if(viss[v])continue;
			viss[v]=1;q.push(v);
		}
		res++;
	}
}
void dfs(int st,int cnt){
	if(cnt>=k){
		int ltk=0;
		for(int i=0;i<dot.size();i++){
			if(!vis[dot[i]]){
				bfs(dot[i]);
				ltk++;
			}
		}
		if(ltk>2)return;
		int dis=0;
		for(int i=1;i<=n;i++){
			bool in=0;
			for(auto d:dot)
				if(i==d)in=1;
			if(in)continue;
			dis=max(dis,bfs1(i));
		}
		ans=min(ans,dis);
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)viss[i]=0;
	for(int i=st+1;i<=n;i++){
		dot.push_back(i);
		dfs(i,cnt+1);
		dot.pop_back();
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fast_read();
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		dot.clear();ans=1e18;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)viss[i]=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
