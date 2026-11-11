#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int o,n,k,ans;
bool vis[100010];
bool vi[100010];
vector<int> v[100010];
void bfs(int s){
	vi[s]=true;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int d=q.front();
		q.pop();
		for(int x:v[d]){
			if(vis[x] && !vi[x]){
				vi[x]=true;
				q.push(x);
			}
		}
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int dis[100010]={};
		queue<int> q;
		q.push(i);
		dis[i]=1;
		while(q.size()){
			int d=q.front(),f=0;
			q.pop();
			for(int x:v[d]){
				if(!dis[x]){
					q.push(x);
					dis[x]=dis[d]+1;
					if(vis[x]){
						ans=max(ans,dis[d]);
						f=1;
						break;
					}
				}
			}
			if(f) break;
		}
	}
	return ans;
}
void dfs(int x,int c){
	if(x>n){
		if(c) return;
		vector<int> v;
		int cnt=0;
		for(int i=1;i<=n;i++){ 
			if(vis[i]){
				v.push_back(i);
				if(!vi[i]) bfs(i),cnt++;
			}
		}
		if(cnt==2) ans=min(ans,solve());
		for(int x:v) vi[x]=false;
		return;
	}
	dfs(x+1,c);
	if(c){
		vis[x]=true;
		dfs(x+1,c-1);
		vis[x]=false;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>o>>o;
	while(o--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++) vis[i]=false;
		dfs(1,k);
		cout<<ans<<'\n';
	}
	return 0;
}
