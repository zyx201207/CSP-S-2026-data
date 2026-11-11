#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=1e6+5;
struct node{
	int u,w;
	bool operator<(const node&o)const{
		return w<o.w;
	}
};
int tid,t;
int n,k;
int Ans; 
int vis[N];
int dis[N];
int dep[N];
int mdep[N];
vector<int>g[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	mdep[u]=dep[u];
	for(int &v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		mdep[u]=max(mdep[u],mdep[v]);
	} 
	return ;
}
bool check(){
	queue<int>q;
	rep(i,1,n)dep[i]=0;
	rep(i,1,n){
		if(vis[i]){
			q.push(i);
			dep[i]=1;
			break;
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int &v:g[u]){
			if(!dep[v]){
				dep[v]=1;
				q.push(v);
			}
		}
	}
	rep(i,1,n){
		if(!dep[i]&&vis[i]){
			q.push(i);
			dep[i]=1;
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int &v:g[u]){
			if(!dep[v]){
				dep[v]=1;
				q.push(v);
			}
		}
	}
	rep(i,1,n){
		if(!dep[i]&&vis[i]){
			return false;
		}
	}
	return true;
}
void Dfs(int x,int cnt){
	if(x==n+1){
		if(cnt!=k)return ;
		if(!check())return ;
		queue<int>q;
		rep(i,1,n){
			if(vis[i])q.push(i),dis[i]=0;
			else dis[i]=1e18;
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int &v:g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v); 
				}
			}
		}
		int ans=0;
		rep(i,1,n)ans=max(ans,dis[i]);
		Ans=min(Ans,ans);
		return ;
	}
	if(cnt<k){
		vis[x]=1;
		Dfs(x+1,cnt+1); 
		vis[x]=0;
	}
	Dfs(x+1,cnt);
	return ;
}
void solve(){
	rep(i,1,n)g[i].clear(),vis[i]=0,dis[i]=1e18;
	cin>>n>>k;
	rep(i,2,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(tid<=3){
		Ans=1e18;
		Dfs(1,0);
		cout<<Ans<<"\n";
		return ;
	}
	dfs(1,0);
	int mx=0;
	rep(i,1,n){
		if(dep[i]>dep[mx])mx=i;
	}
	dfs(mx,0);
	int rt=0;
	mx=0;
	rep(i,1,n){
		mx=max(mx,dep[i]);
	}
	rep(i,1,n){
		if(dep[i]==(int)(mx+1)/2){
			rt=i;
			break;
		}
	}
	dfs(rt,0);
	priority_queue<node>pq;
	rep(i,1,n)pq.push({i,mdep[i]});
	while(k--){
		vis[pq.top().u]=1;
		pq.pop();
	}
	if(pq.size()==1)cout<<0<<"\n";
	else{
		queue<int>q;
		rep(i,1,n){
			if(vis[i])q.push(i),dis[i]=0;
			else dis[i]=1e18;
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int &v:g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v); 
				}
			}
		}
		int ans=0;
		rep(i,1,n)ans=max(ans,dis[i]);
		cout<<ans<<"\n";
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tid>>t;
	while(t--)solve();
	return 0;
}
