#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
using namespace std;
mt19937_64 rd(time(0));
const int N=1e5+5;
int n,dis[N],bo[N],vis[N],ans,k;
vector<int>e[N];
void dfs2(int x){
	vis[x]=1;
	for(int v:e[x]){
		if(vis[v]||!bo[v])continue;
		dfs2(v);
	}
}
void check(){int sum=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(bo[i])dis[i]=0;
		else dis[i]=n+1;
		if(!vis[i]&&bo[i]){
			sum++;
			dfs2(i);
		}
		if(sum>2)break;
	}
	if(sum>2)return;//for(int i=1;i<=n;i++)cout<<bo[i]<<' ';
	deque<int>q;int mx=0;
	for(int i=1;i<=n;i++)if(bo[i])q.pb(i);
	while(q.size()){
		int x=q.front();q.pop_front();
		mx=max(mx,dis[x]);
		if(mx>ans)return;
		for(int v:e[x]){
			if(dis[v]>dis[x]+1){
				dis[v]=dis[x]+1;q.pb(v);
			}
		}
	}
	ans=min(ans,mx);
}
void dfs(int x,int now){
	if(now>k)return;
	if(x==n+1){
		if(now!=k)return;
		check();
		return;
	}
	if(n-x+1+now<k)return;
	bo[x]=1;dfs(x+1,now+1);
	bo[x]=0;dfs(x+1,now);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=n+1;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].pb(v);e[v].pb(u);
		}
		dfs(1,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)e[i].clear();
		
	}
	return 0;
}

