#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
vector<int>way[N];
int vis[N];
void bfs(int x){
	queue<int>q;
	q.push(x);
	while(q.size()){
		int node=q.front();q.pop();
		if(k==0)return;
		for(int i:way[x]){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
				k--;
			}
		}
	}
}
int dfs(int x,int fr){
	int ans=1e9;
	if(vis[x])return 0;
	for(int i:way[x]){
		if(i==fr)continue;
		ans=min(dfs(i,x)+1,ans);
	}
	return ans;
}
void solve(){
	int ans=0;
	cin>>n>>k;
	if(n==k){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		way[u].push_back(v);
		way[v].push_back(u);
	}int la=1e9,nu=0;
	for(int i=1;i<=n;i++){
		if(way[i].size()<la){
			la=way[i].size();
			nu=i;
		}
	}bfs(nu);
	for(int i=1;i<=n;i++){
		ans=max(dfs(i,-1),ans);
	}cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
}

