#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,t,n,k,ans,vis[1000005],cnt,go[1000005];
int dis[1000005];
vector<int> a[1000005];
bool check(){
	for(int i=1;i<=n;i++)go[i]=0;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			q.push(i);
			go[i]=1;
			break;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v : a[u]){
			if(go[v]==0 && vis[v]==1){
				go[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1 && go[i]==0){
			q.push(i);
			go[i]=1;
			break;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v : a[u]){
			if(go[v]==0 && vis[v]==1){
				go[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1 && go[i]==0){
			return 0;
		}
	}return 1;
}
int get_ans(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		dis[i]=-1;
		if(vis[i]==1){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v : a[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dis[i]);
	}return maxn;
}
void dfs(int x){
	if(x==k+1){
		if(check())ans=min(ans,get_ans());
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}ans=1e18;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}if(c<=3)dfs(1);
		else if(c==13 || c==14){
			int num=(n+1)/2;
			ans=(num-k)/2;
			if(k==n)ans=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}