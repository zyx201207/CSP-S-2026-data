#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
vector<int> g[200005];
int k, n;
bool vis[200005];
int bfs(int st){
	queue<pr> q;
	q.push({st, 0});
	int s=k;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	vis[st]=1;
	while(!q.empty()){
		s--;
		int u=q.front().fi, h=q.front().se;
		q.pop();
		if(!s){
			return 2*h-1;
		}
		for(auto v:g[u]){
			if(vis[v]) continue;
			q.push({v, h+1});
			vis[v]=1;
		}
	}
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--){
		if(c<=8){
			cin>>n>>k;
			int mi=INT_MAX;
			for(int i=1;i<=n;i++)
				g[i].clear();
			for(int i=1;i<n;i++){
				int u, v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			for(int i=1;i<=n;i++)
				mi=min(mi, bfs(i));
			cout<<mi<<'\n';
		}
		else{
			cout<<"郡猫雅猫长长久久！！！";
		}
	} 
	return 0;
}
//我想加入魔怔行为大赏！！！(真诚) 
